/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef HEADER_GUARD_VICK_PREDICATES_H
#define HEADER_GUARD_VICK_PREDICATES_H

#include "contents.hh"

namespace vick {
namespace predicates {

/*!
 * \file vick-predicates/lib.hh
 * \brief Define basic predicates.
 */

/*! \brief Test if the point is at the first possible point in the buffer */
bool start_of_buffer(const contents&);
/*! \brief Test if the point is at the last possible point in the buffer */
bool end_of_buffer(const contents&);

/*! \brief Test if the point is at the first possible point in the line */
bool start_of_line(const contents&);
/*! \brief Test if the point is at the last possible point in the line */
bool end_of_line(const contents&);

/*! \brief Test if character at point passes std::isspace */
bool at_whitespace(const contents&);
/*! \brief Test if character at point is in DELIMINATORS */
bool at_deliminator(const contents&);
/*! \brief Test if character at point doesn't pass is_whitespace or
 *  is_deliminator */
bool at_regular(const contents&);

/*! \brief Test if character passes std::isspace */
bool is_whitespace(char);
/*! \brief Test if character is in DELIMINATORS */
bool is_deliminator(char);
/*! \brief Test if character doesn't pass is_whitespace or
 *  is_deliminator. */
bool is_regular(char);
}
}

#endif
