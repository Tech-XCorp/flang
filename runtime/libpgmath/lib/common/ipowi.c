/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "mthdecls.h"

int
__mth_i_ipowi(int x, int i)
{
  int f;

  /* special cases */

  if (x == 2) {
    if (i >= 0)
      return 1 << i;
    return 0;
  }
  if (i < 0) {
    if (x == 1)
      return 1;
    if (x == -1) {
      if (i & 1)
        return -1;
      return 1;
    }
    return 0;
  }

  if (i == 0)
    return 1;
  f = 1;
  while (1) {
    if (i & 1)
      f *= x;
    i >>= 1;
    if (i == 0)
      return f;
    x *= x;
  }
}
