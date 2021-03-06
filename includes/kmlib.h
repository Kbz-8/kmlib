/**
 * This file is a part of the kmlib (kbz_8 main library)
 *
 * Copyright (C) 2022 @kbz_8
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __KMLIB__
#define __KMLIB__

#include "km_io.h"
#include "km_errno.h"
#include "km_memory.h"
#include "km_strings.h"
#include "km_va_args.h"
#include "km_alltypes.h"

#define abort() km_abort()
#define exit(status) km_exit(status)
#define atexit(func) km_atexit(func)

void km_exit(int status);
void km_abort();
int km_atexit(void (*func)(void));

void km_assert(int cond, const char* file, const char* line);

#undef km_assert
#define km_assert(cond) km_assert(cond, __FILE__, __LINE__)

#endif // __KMLIB__
