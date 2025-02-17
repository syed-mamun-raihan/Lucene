#pragma once
#include "stringhelper.h"
#include <memory>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/search/highlight/TokenGroup.h"

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
namespace org::apache::lucene::search::highlight
{
/**
 * Processes terms found in the original text, typically by applying some form
 * of mark-up to highlight terms in HTML search results pages.
 *
 */
class Formatter
{
  GET_CLASS_NAME(Formatter)
  /**
   * @param originalText The section of text being considered for markup
   * @param tokenGroup contains one or several overlapping Tokens along with
   * their scores and positions.
   */
public:
  virtual std::wstring
  highlightTerm(const std::wstring &originalText,
                std::shared_ptr<TokenGroup> tokenGroup) = 0;
};

} // #include  "core/src/java/org/apache/lucene/search/highlight/
