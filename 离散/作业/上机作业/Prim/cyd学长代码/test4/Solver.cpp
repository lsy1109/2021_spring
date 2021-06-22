/**
/**
 * COPYRIGHT NOTICE
 * Copyright (c) 2019, Institute of CG & CAD, Tsinghua University.
 * All Rights Reserved.
 *
 * @file    Solver.cpp
 * @brief   Solver class declaration.
 *
 * This file declares ...
 *
 * @version 1.2
 * @author  Jackie Pang
 * @e-mail: 15pengyi@gmail.com
 * @date    2012/10/10
 * @reviser	Zhang Mingdong
 * @date	2017/10/10
 * @e-mail:	zhangmd14@mails.tsinghua.edu.cn
 * @reviser	Xiao Dong
 * @date	2019/03/18
 * @e-mail:	xiaodong14ry@163.com
 */

#include <iostream>

#include "Solver.h"

Solver::Solver()
    : error(true)
{}

Solver::~Solver()
{
    if (inputStream) inputStream.close();
}

Solver::Solver(const std::string &fileName)
    : error(false)
{
    inputStream.open(fileName.c_str());
    if (!inputStream)
    {
        std::cerr << " > ERROR: unable to open input file: \"" << fileName << "\"." <<  std::endl;
        error = true;
    }
}

const std::string Solver::GetAnswer()
{
    if (error) outputStream.str("ERROR");
    return outputStream.str();
}

void Solver::Solve(std::istream &inputStream, std::ostream &outputStream)
{

}