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

#include <cstdlib>
#include <string>
#include "Util.h"

/*static*/ int Util::Bin2Dec(const string& bin)
{
    return (int) strtol(bin.c_str(), NULL, 2);
}

/*static*/ int Util::Hex2Dec(const string& hex)
{
    return (int) strtol(hex.c_str(), NULL, 16);
}

/*static*/ string Util::Bin2Hex(const string& bin)
{
    string ret;
    string buffer;

    for (size_t i = 0; i < bin.length(); i += 4)
    {
        buffer = bin.substr(i, 4);
        char h = hexString[Bin2Dec(buffer)];

        ret += h;
    }

    return ret;
}

/*static*/ string Util::Hex2Bin(const string& hex)
{
    string ret;
    string buffer;
    for (size_t i = 0; i < hex.length(); i++)
    {
        buffer = hex.substr(i, 1);
        ret += binArray[Hex2Dec(buffer)];
    }

    return ret;
}

/*static*/ void Util::PadTo(string &str, const size_t num, char paddingChar)
{
    if (num > str.size())
        str.insert(0, num - str.size(), paddingChar);
}

/*static*/ string Util::Int2Str(int theInt)
{
    ostringstream ss;
    ss << theInt;
    return ss.str();
}
