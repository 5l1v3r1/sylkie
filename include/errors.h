// Copyright (c) 2017 Daniel L. Robertson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef SYLKIE_INCLUDE_ERRORS_H
#define SYLKIE_INCLUDE_ERRORS_H

#include <errno.h>

/**
 * \defgroup errors sylkie_error structures and methods
 * \ingroup libsylkie
 * @{
 */

/**
 * \brief Error types
 */
enum sylkie_error {
    SYLKIE_SUCCESS = 0,
    SYLKIE_FATAL,
    SYLKIE_NULL_INPUT,
    SYLKIE_NO_DEVICE,
    SYLKIE_NOT_FOUND,
    SYLKIE_SYSCALL_FAILED,
    SYLKIE_NO_MEM,
    SYLKIE_TOO_LARGE,
    SYLKIE_EPERM,
    SYLKIE_EAGAIN,
    SYLKIE_EINVAL,
    SYLKIE_INVALID_ERR,
};

/**
 * \brief Return the human readable string for the given error
 * \param err error to convert to string
 */
const char* sylkie_strerror(const enum sylkie_error err);

/**
 * \brief Set err to new_err
 * \param err Pointer to error that will be set
 * \param new_err Value err will be set to
 *
 * Note: This also checks if the type is different and err is not null
 */
void sylkie_error_set(enum sylkie_error* err, enum sylkie_error new_err);

/**
 * \brief Attempt to convert errno into a sylkie_error
 * \param err Pointer to error that will be set to the converted error
 */
void sylkie_error_from_errno(enum sylkie_error* err);

/// @} end of doxygen errors group

#endif
