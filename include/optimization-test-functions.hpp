/*
 MIT License

 Copyright (c) 2019 Yuki Koyama

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef OPTIMIZATION_TEST_FUNCTIONS_HPP_
#define OPTIMIZATION_TEST_FUNCTIONS_HPP_

#include <cassert>
#if defined(OTF_WITH_EIGEN)
#include <Eigen/Core>
#endif

namespace otf
{
    enum class FunctionType
    {
        Rosenbrock,
    };

    inline double GetValue(const double x[], const int n, const FunctionType type = FunctionType::Rosenbrock)
    {
        switch (type) {
            case FunctionType::Rosenbrock:
            {
                assert(n >= 2);
                double value = 0.0;
                for (int i = 0; i < n - 1; ++ i)
                {
                    value += 100.0 * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]) + (1.0 - x[i]) * (1.0 - x[i]);
                }
                return value;
            }
        }
    }

#if defined(OTF_WITH_EIGEN)
    inline double GetValue(const Eigen::VectorXd& x, const FunctionType type = FunctionType::Rosenbrock)
    {
        return GetValue(x.data(), x.size(), type);
    }
#endif
}

#endif
