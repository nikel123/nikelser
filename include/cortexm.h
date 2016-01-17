/**
 * Copyright (c) 2013-2015 Andrej Gelenberg <andrej.gelenberg@udo.edu>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _CORTEXM_H
#define _CORTEXM_H

#include <armv7m.h>

bf_reg_funcs(32, SCB_ACTLR_DISOOFP,    9, 1)
bf_reg_funcs(32, SCB_ACTLR_DISFPCA,    8, 1)
bf_reg_funcs(32, SCB_ACTLR_DISFOLD,    2, 1)
bf_reg_funcs(32, SCB_ACTLR_DISDEFWBUF, 1, 1)
bf_reg_funcs(32, SCB_ACTLR_DISMCYCINT, 0, 1)

#endif // _CORTEXM_H
