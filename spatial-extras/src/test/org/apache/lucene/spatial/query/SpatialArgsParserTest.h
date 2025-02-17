#pragma once
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/spatial/query/SpatialOperation.h"

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
namespace org::apache::lucene::spatial::query
{

using org::locationtech::spatial4j::context::SpatialContext;
using LuceneTestCase = org::apache::lucene::util::LuceneTestCase;

// Tests SpatialOperation somewhat too
class SpatialArgsParserTest : public LuceneTestCase
{
  GET_CLASS_NAME(SpatialArgsParserTest)

private:
  std::shared_ptr<SpatialContext> ctx = SpatialContext::GEO;

  // The args parser is only dependent on the ctx for IO so I don't care to test
  // with other implementations.

public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testArgsParser() throws Exception
  virtual void testArgsParser() ;

private:
  void assertAlias(std::shared_ptr<SpatialOperation> op,
                   const std::wstring &name) ;

protected:
  std::shared_ptr<SpatialArgsParserTest> shared_from_this()
  {
    return std::static_pointer_cast<SpatialArgsParserTest>(
        org.apache.lucene.util.LuceneTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/spatial/query/
