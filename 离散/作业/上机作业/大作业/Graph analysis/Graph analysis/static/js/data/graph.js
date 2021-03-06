// Graph data
// You can add any fields into the following ararys and show it by any encodings
// For example, in for_directed_layout.js, closeness is encoded by color, betweenness is encoded by point radius, etc.
var nodes = [
	{"name": 0, "betweenness": 10, "closeness": 2593.03, "connected_component": 0},
	{"name": 1, "betweenness": 9.36905, "closeness": 1479.45, "connected_component": 0},
	{"name": 2, "betweenness": 351.267, "closeness": 1210.63, "connected_component": 0},
	{"name": 3, "betweenness": 49, "closeness": 820.277, "connected_component": 0},
	{"name": 4, "betweenness": 10.6667, "closeness": 1017.49, "connected_component": 0},
	{"name": 5, "betweenness": 0, "closeness": 1254.67, "connected_component": 0},
	{"name": 6, "betweenness": 0, "closeness": 1479.45, "connected_component": 0},
	{"name": 7, "betweenness": 60.05, "closeness": 1479.45, "connected_component": 0},
	{"name": 8, "betweenness": 1822.33, "closeness": 1479.45, "connected_component": 0},
	{"name": 9, "betweenness": 171.633, "closeness": 1631.57, "connected_component": 0},
	{"name": 10, "betweenness": 6, "closeness": 1479.45, "connected_component": 0},
	{"name": 11, "betweenness": 7, "closeness": 1479.45, "connected_component": 0},
	{"name": 12, "betweenness": 72.6667, "closeness": 1479.45, "connected_component": 0},
	{"name": 13, "betweenness": 45.5833, "closeness": 1479.45, "connected_component": 0},
	{"name": 14, "betweenness": 1, "closeness": 1479.45, "connected_component": 0},
	{"name": 15, "betweenness": 7.33333, "closeness": 2260.11, "connected_component": 0},
	{"name": 16, "betweenness": 14.5833, "closeness": 1479.45, "connected_component": 0},
	{"name": 17, "betweenness": 331.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 18, "betweenness": 363.8, "closeness": 1479.45, "connected_component": 0},
	{"name": 19, "betweenness": 34.3, "closeness": 1479.45, "connected_component": 0},
	{"name": 20, "betweenness": 76, "closeness": 1479.45, "connected_component": 0},
	{"name": 21, "betweenness": 4.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 22, "betweenness": 863.333, "closeness": 1479.45, "connected_component": 0},
	{"name": 23, "betweenness": 8.87536, "closeness": 1479.45, "connected_component": 0},
	{"name": 24, "betweenness": 8.36667, "closeness": 1479.45, "connected_component": 0},
	{"name": 25, "betweenness": 0.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 26, "betweenness": 125.056, "closeness": 1479.45, "connected_component": 0},
	{"name": 27, "betweenness": 24.7621, "closeness": 1479.45, "connected_component": 0},
	{"name": 28, "betweenness": 10.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 29, "betweenness": 227.75, "closeness": 1479.45, "connected_component": 0},
	{"name": 30, "betweenness": 4.70238, "closeness": 1479.45, "connected_component": 0},
	{"name": 31, "betweenness": 47.0833, "closeness": 1479.45, "connected_component": 0},
	{"name": 32, "betweenness": 3263.33, "closeness": 1479.45, "connected_component": 0},
	{"name": 33, "betweenness": 3.82507, "closeness": 1479.45, "connected_component": 0},
	{"name": 34, "betweenness": 4, "closeness": 1479.45, "connected_component": 0},
	{"name": 35, "betweenness": 5.62063, "closeness": 1479.45, "connected_component": 0},
	{"name": 36, "betweenness": 0, "closeness": 1479.45, "connected_component": 0},
	{"name": 37, "betweenness": 25.654, "closeness": 1479.45, "connected_component": 0},
	{"name": 38, "betweenness": 125.567, "closeness": 1479.45, "connected_component": 0},
	{"name": 39, "betweenness": 187.25, "closeness": 1479.45, "connected_component": 0},
	{"name": 40, "betweenness": 10.7497, "closeness": 1479.45, "connected_component": 0},
	{"name": 41, "betweenness": 10.7, "closeness": 1479.45, "connected_component": 0},
	{"name": 42, "betweenness": 12, "closeness": 1479.45, "connected_component": 0},
	{"name": 43, "betweenness": 0, "closeness": 1479.45, "connected_component": 0},
	{"name": 44, "betweenness": 234, "closeness": 1479.45, "connected_component": 0},
	{"name": 45, "betweenness": 55.65, "closeness": 1479.45, "connected_component": 0},
	{"name": 46, "betweenness": 122, "closeness": 1479.45, "connected_component": 0},
	{"name": 47, "betweenness": 436.767, "closeness": 2000.45, "connected_component": 0},
	{"name": 48, "betweenness": 1440.17, "closeness": 1479.45, "connected_component": 0},
	{"name": 49, "betweenness": 0, "closeness": 1479.45, "connected_component": 0},
	{"name": 50, "betweenness": 45.3333, "closeness": 1479.45, "connected_component": 0},
	{"name": 51, "betweenness": 10.4, "closeness": 1479.45, "connected_component": 0},
	{"name": 52, "betweenness": 11, "closeness": 1479.45, "connected_component": 0},
	{"name": 53, "betweenness": 58.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 54, "betweenness": 31.3667, "closeness": 1479.45, "connected_component": 0},
	{"name": 55, "betweenness": 199.667, "closeness": 1479.45, "connected_component": 0},
	{"name": 56, "betweenness": 148, "closeness": 1479.45, "connected_component": 0},
	{"name": 57, "betweenness": 632.383, "closeness": 1479.45, "connected_component": 0},
	{"name": 58, "betweenness": 33.2, "closeness": 1479.45, "connected_component": 0},
	{"name": 59, "betweenness": 25.9, "closeness": 1479.45, "connected_component": 0},
	{"name": 60, "betweenness": 21.3333, "closeness": 1479.45, "connected_component": 0},
	{"name": 61, "betweenness": 524.25, "closeness": 1479.45, "connected_component": 0},
	{"name": 62, "betweenness": 0, "closeness": 1479.45, "connected_component": 0},
	{"name": 63, "betweenness": 2.5255, "closeness": 1479.45, "connected_component": 0},
	{"name": 64, "betweenness": 6.91667, "closeness": 1479.45, "connected_component": 0},
	{"name": 65, "betweenness": 8, "closeness": 1479.45, "connected_component": 0},
	{"name": 66, "betweenness": 3.83333, "closeness": 1479.45, "connected_component": 0},
	{"name": 67, "betweenness": 0, "closeness": 1479.45, "connected_component": 0},
	{"name": 68, "betweenness": 123.167, "closeness": 1479.45, "connected_component": 0},
	{"name": 69, "betweenness": 127.498, "closeness": 1479.45, "connected_component": 0},
	{"name": 70, "betweenness": 0.333333, "closeness": 1479.45, "connected_component": 0},
	{"name": 71, "betweenness": 82.4167, "closeness": 1479.45, "connected_component": 0},
	{"name": 72, "betweenness": 10.8333, "closeness": 1479.45, "connected_component": 0},
	{"name": 73, "betweenness": 47, "closeness": 1479.45, "connected_component": 0},
	{"name": 74, "betweenness": 93.4889, "closeness": 1479.45, "connected_component": 0},
	{"name": 75, "betweenness": 83.4167, "closeness": 1479.45, "connected_component": 0},
	{"name": 76, "betweenness": 150.333, "closeness": 1479.45, "connected_component": 0},
	{"name": 77, "betweenness": 15.8095, "closeness": 1479.45, "connected_component": 0},
	{"name": 78, "betweenness": 23, "closeness": 1479.45, "connected_component": 0},
	{"name": 79, "betweenness": 77.3762, "closeness": 1479.45, "connected_component": 0},
	{"name": 80, "betweenness": 2, "closeness": 1479.45, "connected_component": 0},
	{"name": 81, "betweenness": 0.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 82, "betweenness": 644.583, "closeness": 1479.45, "connected_component": 0},
	{"name": 83, "betweenness": 86.6667, "closeness": 1479.45, "connected_component": 0},
	{"name": 84, "betweenness": 3.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 85, "betweenness": 3.83333, "closeness": 1479.45, "connected_component": 0},
	{"name": 86, "betweenness": 0, "closeness": 111.65, "connected_component": 0},
	{"name": 87, "betweenness": 47, "closeness": 423.45, "connected_component": 0},
	{"name": 88, "betweenness": 373, "closeness": 1479.45, "connected_component": 0},
	{"name": 89, "betweenness": 12.6667, "closeness": 412.45, "connected_component": 0},
	{"name": 90, "betweenness": 55.6667, "closeness": 1479.45, "connected_component": 0},
	{"name": 91, "betweenness": 8.0619, "closeness": 1479.45, "connected_component": 0},
	{"name": 92, "betweenness": 51.0833, "closeness": 1479.45, "connected_component": 0},
	{"name": 93, "betweenness": 44.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 94, "betweenness": 31.5, "closeness": 1479.45, "connected_component": 0},
	{"name": 95, "betweenness": 16.3111, "closeness": 34.45, "connected_component": 0},
	{"name": 96, "betweenness": 0.833333, "closeness": 1479.45, "connected_component": 0},
	{"name": 97, "betweenness": 1, "closeness": 1479.45, "connected_component": 0},
	{"name": 98, "betweenness": 39.4, "closeness": 1479.45, "connected_component": 0},
	{"name": 99, "betweenness": 50.5, "closeness": 2593.03, "connected_component": 0}
];

// The source and the target in "links" refer to the indices of "nodes"
// For example, {"source":0,"target":3, "weight": 1} refer to an edge from {"name": 0, "betweenness": 10, "closeness": 2593.03, "connected_component": 0} to {"name": 3, "betweenness": 49, "closeness": 820.277, "connected_component": 0}, and it has nothing to do with the field "name" in "nodes"

var links = [
	{"source":0,"target":3, "weight": 1},
	{"source":1,"target":4, "weight": 1},
	{"source":2,"target":5, "weight": 1},
	{"source":3,"target":6, "weight": 1},
	{"source":4,"target":7, "weight": 1},
	{"source":5,"target":8, "weight": 1},
	{"source":6,"target":9, "weight": 1},
	{"source":7,"target":10, "weight": 1},
	{"source":8,"target":11, "weight": 1},
	{"source":9,"target":12, "weight": 1},
	{"source":10,"target":13, "weight": 1},
	{"source":11,"target":14, "weight": 1},
	{"source":12,"target":15, "weight": 1},
	{"source":13,"target":16, "weight": 1},
	{"source":14,"target":17, "weight": 1},
	{"source":15,"target":18, "weight": 1},
	{"source":16,"target":19, "weight": 1},
	{"source":17,"target":20, "weight": 1},
	{"source":18,"target":21, "weight": 1},
	{"source":19,"target":22, "weight": 1},
	{"source":20,"target":23, "weight": 1},
	{"source":21,"target":24, "weight": 1},
	{"source":22,"target":25, "weight": 1},
	{"source":23,"target":26, "weight": 1},
	{"source":24,"target":27, "weight": 1},
	{"source":25,"target":28, "weight": 1},
	{"source":26,"target":29, "weight": 1},
	{"source":27,"target":30, "weight": 1},
	{"source":28,"target":31, "weight": 1},
	{"source":29,"target":32, "weight": 1},
	{"source":30,"target":33, "weight": 1},
	{"source":31,"target":34, "weight": 1},
	{"source":32,"target":35, "weight": 1},
	{"source":33,"target":36, "weight": 1},
	{"source":34,"target":37, "weight": 1},
	{"source":35,"target":38, "weight": 1},
	{"source":36,"target":39, "weight": 1},
	{"source":37,"target":40, "weight": 1},
	{"source":38,"target":41, "weight": 1},
	{"source":39,"target":42, "weight": 1},
	{"source":40,"target":43, "weight": 1},
	{"source":41,"target":44, "weight": 1},
	{"source":42,"target":45, "weight": 1},
	{"source":43,"target":46, "weight": 1},
	{"source":44,"target":47, "weight": 1},
	{"source":45,"target":48, "weight": 1},
	{"source":46,"target":49, "weight": 1},
	{"source":47,"target":50, "weight": 1},
	{"source":48,"target":51, "weight": 1},
	{"source":49,"target":52, "weight": 1},
	{"source":50,"target":53, "weight": 1},
	{"source":51,"target":54, "weight": 1},
	{"source":52,"target":55, "weight": 1},
	{"source":53,"target":56, "weight": 1},
	{"source":54,"target":57, "weight": 1},
	{"source":55,"target":58, "weight": 1},
	{"source":56,"target":59, "weight": 1},
	{"source":57,"target":60, "weight": 1},
	{"source":58,"target":61, "weight": 1},
	{"source":59,"target":62, "weight": 1},
	{"source":60,"target":63, "weight": 1},
	{"source":61,"target":64, "weight": 1},
	{"source":62,"target":65, "weight": 1},
	{"source":63,"target":66, "weight": 1},
	{"source":64,"target":67, "weight": 1},
	{"source":65,"target":68, "weight": 1},
	{"source":66,"target":69, "weight": 1},
	{"source":67,"target":70, "weight": 1},
	{"source":68,"target":71, "weight": 1},
	{"source":69,"target":72, "weight": 1},
	{"source":70,"target":73, "weight": 1},
	{"source":71,"target":74, "weight": 1},
	{"source":72,"target":75, "weight": 1},
	{"source":73,"target":76, "weight": 1},
	{"source":74,"target":77, "weight": 1},
	{"source":75,"target":78, "weight": 1},
	{"source":76,"target":79, "weight": 1},
	{"source":77,"target":80, "weight": 1},
	{"source":78,"target":81, "weight": 1},
	{"source":79,"target":82, "weight": 1},
	{"source":85,"target":83, "weight": 1},
	{"source":81,"target":84, "weight": 1},
	{"source":84,"target":85, "weight": 1},
	{"source":82,"target":86, "weight": 1},
	{"source":83,"target":87, "weight": 1},
	{"source":84,"target":88, "weight": 1},
	{"source":84,"target":89, "weight": 1},
	{"source":84,"target":90, "weight": 1},
	{"source":84,"target":91, "weight": 1},
	{"source":84,"target":92, "weight": 1},
	{"source":94,"target":93, "weight": 1},
	{"source":91,"target":94, "weight": 1},
	{"source":92,"target":95, "weight": 1},
	{"source":93,"target":96, "weight": 1},
	{"source":94,"target":97, "weight": 1},
	{"source":95,"target":98, "weight": 1},
	{"source":96,"target":99, "weight": 1},
	{"source":97,"target":0, "weight": 1},
	{"source":98,"target":1, "weight": 1},
	{"source":99,"target":2, "weight": 1}
]