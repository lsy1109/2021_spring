var width = 800,
    height = 600,
    svg = d3.select("#graph").append("svg").attr("width", 960).attr("height", 600),
    g = svg.append("g").attr("transform", "translate(" + width / 2 + "," + height / 2 + ")");

var color = d3.scaleOrdinal(d3.schemeCategory20);

var simulation = d3.forceSimulation(nodes)
    .force("charge", d3.forceManyBody().strength(-80))
    .force("link", d3.forceLink(links).distance(20).strength(1).iterations(10))
    .force("x", d3.forceX())
    .force("y", d3.forceY())
    .stop();

var loading = svg.append("text")
    .attr("dy", "0.35em")
    .attr("text-anchor", "middle")
    .attr("font-family", "sans-serif")
    .attr("font-size", 10)
    .text("Simulating. One moment please…");

var dragstarted = function(d) {
    if (!d3.event.active) {
        simulation.alpha(.5);
        simulation.alphaTarget(0.1).restart();
    }
    d.fx = d.x;
    d.fy = d.y;
}

var dragged = function (d) {
    d.fx = d3.event.x;
    d.fy = d3.event.y;
}

var dragended = function(d) {
    if (!d3.event.active) simulation.alphaTarget(0.0001);
    d.fx = null;
    d.fy = null;
}

var ticked = function() {
    g.selectAll("line")
        .attr("x1", d => d.source.x)
        .attr("y1", d => d.source.y)
        .attr("x2", d => d.target.x)
        .attr("y2", d => d.target.y);

    g.selectAll('circle')
        .attr("cx", d => d.x)
        .attr("cy", d => d.y);
}

var mst_edgeset = new Set(mst.map(d => d.source + '-' + d.target))

// Use a timeout to allow the rest of the page to load first.
d3.timeout(function() {

    loading.remove();
    
    for (var i = 0, n = Math.ceil(Math.log(simulation.alphaMin()) / Math.log(1 - simulation.alphaDecay())); i < n; ++i) {
        simulation.tick();
    }

    // Note: the encodings can be changed as you need

    g.append("g")
        .attr("id", "link")
        .attr("stroke", "lightgray")
        .attr("stroke-width", 1.5)
        .selectAll("line")
        .data(links)
        .enter()
        .append("line")
        .attr("class", "link")
        .attr("x1", d => d.source.x)
        .attr("y1", d => d.source.y)
        .attr("x2", d => d.target.x)
        .attr("y2", d => d.target.y)
        // Line width encodes edge weight
        .attr("stroke-width", d => d.weight)
        // Highlight some edges, like MST or shortest path between two nodes
        .each(function(d) {
            if (mst_edgeset.has(d.source.index + '-' + d.target.index)) {
                d3.select(this)
                    .attr("stroke", "black")
            }
        });

    g.append("g")
        .attr("stroke", "lightgray")
        .attr("stroke-width", 1.5)
        .selectAll("circle")
        .data(nodes)
        .enter()
        .append("circle")
        .attr("class", "node")
        .attr("cx", d => d.x)
        .attr("cy", d => d.y)
        // Encoded by centrality
        // .attr("r", d => Math.sqrt(d.betweenness / 5))
        // .style("fill", d => color(Math.floor(Math.sqrt(d.closeness))))
        // Encoded by connected components
        .attr("r", 4.5)
        .style("fill", d => color(d.connect_component))
        .call(d3.drag()
            .on("start", dragstarted)
            .on("drag", dragged)
            .on("end", dragended)
        );

    simulation.on("tick", ticked);
});