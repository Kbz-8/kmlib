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

#ifndef __KM_IO__
#define __KM_IO__

#include "km_alltypes.h"

size_t km_print(const char* out);
size_t km_println(const char* out);
size_t km_printf(const char* out, ...);

km_file km_fopen(const char* path, int mode);
void km_fwrite(km_file file, const char* message, int len);
void km_fread(km_file file, char* buffer);
void km_fclose(km_file file);

#endif // __KM_IO__
