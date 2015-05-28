/*
 * This file is copyright 2015 Thiago Neves <thiago.nsantos@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THIAGO NEVES BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <sstream>

using namespace std;

class Util
{
public:
    static int Bin2Dec(const string& bin);
    static int Hex2Dec(const string& hex);
    static string Bin2Hex(const string& bin);
    static string Hex2Bin(const string& hex);
    static void PadTo(string &str, const size_t num, char paddingChar);
    static string Int2Str(int theInt);
};

static string hexString = "0123456789ABCDEF";
static string binArray[] = { "0000", // 0
                             "0001", // 1
                             "0010", // 2
                             "0011", // 3
                             "0100", // 4
                             "0101", // 5
                             "0110", // 6
                             "0111", // 7
                             "1000", // 8
                             "1001", // 9
                             "1010", // 10
                             "1011", // 11
                             "1100", // 12
                             "1101", // 13
                             "1110", // 14
                             "1111" // 15
                           };

#endif //UTIL_H
