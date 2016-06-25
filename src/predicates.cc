/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "../lib.hh"
#include "configuration.hh"
#include <algorithm>

namespace vick {
namespace predicates {
bool start_of_buffer(const contents& c) {
    return c.x == 0 and c.y == 0;
}
bool end_of_buffer(const contents& c) {
    return c.cont.empty() or
           (c.y == c.cont.size() - 1 and c.x == c.cont.back().size());
}

bool start_of_line(const contents& c) {
    return c.x == 0;
}
bool end_of_line(const contents& c) {
    return c.cont.empty() or
        c.x == c.cont[c.y].size();
}

bool at_whitespace(const contents& c) {
    return is_whitespace(c.cont[c.y][c.x]);
}
bool at_deliminator(const contents& c) {
    return is_deliminator(c.cont[c.y][c.x]);
}
bool at_regular(const contents& c) {
    return is_regular(c.cont[c.y][c.x]);
}

bool is_whitespace(char c) {
    return std::isspace(c);
}
bool is_deliminator(char c) {
    return std::find(DELIMINATORS.begin(), DELIMINATORS.end(),
                     c) != DELIMINATORS.end();
}
bool is_regular(char c) {
    return not is_whitespace(c) and not is_deliminator(c);
}
}
}
