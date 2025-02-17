#pragma once
#include "stringhelper.h"
#include <memory>
#include <stdexcept>

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
namespace org::apache::lucene::spatial::deque
{

using StrategyTestCase = org::apache::lucene::spatial::StrategyTestCase;

class TestPointVectorStrategy : public StrategyTestCase
{
  GET_CLASS_NAME(TestPointVectorStrategy)

public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Before @Override public void setUp() throws Exception
  void setUp()  override;

  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testCircleShapeSupport()
  virtual void testCircleShapeSupport();

  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test(expected = UnsupportedOperationException.class) public
  // void testInvalidQueryShape()
  virtual void testInvalidQueryShape();

  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testCitiesIntersectsBBox() throws
  // java.io.IOException
  virtual void testCitiesIntersectsBBox() ;

  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testFieldOptions() throws
  // java.io.IOException, java.text.ParseException
  virtual void testFieldOptions() ;

protected:
  std::shared_ptr<TestPointVectorStrategy> shared_from_this()
  {
    return std::static_pointer_cast<TestPointVectorStrategy>(
        org.apache.lucene.spatial.StrategyTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/spatial/deque/
