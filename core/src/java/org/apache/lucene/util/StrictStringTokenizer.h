#pragma once
#include "exceptionhelper.h"
#include "stringhelper.h"
#include <memory>
#include <string>

/*
 * Licensed to the Syed Mamun Raihan (sraihan.com) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * sraihan.com licenses this file to You under GPLv3 License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
namespace org::apache::lucene::util
{

/** Used for parsing Version strings so we don't have to
 *  use overkill std::wstring.split nor StringTokenizer (which silently
 *  skips empty tokens). */

class StrictStringTokenizer final
    : public std::enable_shared_from_this<StrictStringTokenizer>
{
  GET_CLASS_NAME(StrictStringTokenizer)

public:
  StrictStringTokenizer(const std::wstring &s, wchar_t delimiter);

  std::wstring nextToken();

  bool hasMoreTokens();

private:
  const std::wstring s;
  const wchar_t delimiter;
  int pos = 0;
};

} // #include  "core/src/java/org/apache/lucene/util/
