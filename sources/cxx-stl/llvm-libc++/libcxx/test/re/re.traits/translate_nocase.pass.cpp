// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <regex>

// template <class charT> struct regex_traits;

// charT translate_nocase(charT c) const;

// XFAIL: with_system_lib=x86_64-apple-darwin11
// XFAIL: with_system_lib=x86_64-apple-darwin12

#include <regex>
#include <cassert>

#include "platform_support.h"

int main()
{
    {
        std::regex_traits<char> t;
        assert(t.translate_nocase(' ') == ' ');
        assert(t.translate_nocase('A') == 'a');
        assert(t.translate_nocase('\x07') == '\x07');
        assert(t.translate_nocase('.') == '.');
        assert(t.translate_nocase('a') == 'a');
        assert(t.translate_nocase('1') == '1');
        assert(t.translate_nocase('\xDA') == '\xDA');
        assert(t.translate_nocase('\xFA') == '\xFA');
/* Disable locale specific tests on Android because Android's NDK does not
 * support locales other than "C" and "POSIX".
 *
 * https://code.google.com/p/android/issues/detail?id=57313
 */
#if 0
        t.imbue(std::locale(LOCALE_en_US_UTF_8));
        assert(t.translate_nocase(' ') == ' ');
        assert(t.translate_nocase('A') == 'a');
        assert(t.translate_nocase('\x07') == '\x07');
        assert(t.translate_nocase('.') == '.');
        assert(t.translate_nocase('a') == 'a');
        assert(t.translate_nocase('1') == '1');
        assert(t.translate_nocase('\xDA') == '\xFA');
        assert(t.translate_nocase('\xFA') == '\xFA');
#endif
    }
    {
        std::regex_traits<wchar_t> t;
        assert(t.translate_nocase(L' ') == L' ');
        assert(t.translate_nocase(L'A') == L'a');
        assert(t.translate_nocase(L'\x07') == L'\x07');
        assert(t.translate_nocase(L'.') == L'.');
        assert(t.translate_nocase(L'a') == L'a');
        assert(t.translate_nocase(L'1') == L'1');
        assert(t.translate_nocase(L'\xDA') == L'\xDA');
        assert(t.translate_nocase(L'\xFA') == L'\xFA');
/* Disable locale specific tests on Android because Android's NDK does not
 * support locales other than "C" and "POSIX".
 *
 * https://code.google.com/p/android/issues/detail?id=57313
 */
#if 0
        t.imbue(std::locale(LOCALE_en_US_UTF_8));
        assert(t.translate_nocase(L' ') == L' ');
        assert(t.translate_nocase(L'A') == L'a');
        assert(t.translate_nocase(L'\x07') == L'\x07');
        assert(t.translate_nocase(L'.') == L'.');
        assert(t.translate_nocase(L'a') == L'a');
        assert(t.translate_nocase(L'1') == L'1');
        assert(t.translate_nocase(L'\xDA') == L'\xFA');
        assert(t.translate_nocase(L'\xFA') == L'\xFA');
#endif
    }
}
