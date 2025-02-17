#pragma once
#include "stringhelper.h"
#include <iostream>
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
namespace org::apache::lucene::util
{

/**
 * Ensures proper functions of {@link LuceneTestCase#setUp()}
 * and {@link LuceneTestCase#tearDown()}.
 */
class TestSetupTeardownChaining : public WithNestedTests
{
  GET_CLASS_NAME(TestSetupTeardownChaining)
public:
  class NestedSetupChain : public AbstractNestedTest
  {
    GET_CLASS_NAME(NestedSetupChain)
  public:
    void setUp()  override;

    // C++ TODO: Most Java annotations will not have direct C++ equivalents:
    // ORIGINAL LINE: @Test public void testMe()
    virtual void testMe();

  protected:
    std::shared_ptr<NestedSetupChain> shared_from_this()
    {
      return std::static_pointer_cast<NestedSetupChain>(
          AbstractNestedTest::shared_from_this());
    }
  };

public:
  class NestedTeardownChain : public AbstractNestedTest
  {
    GET_CLASS_NAME(NestedTeardownChain)
  public:
    void tearDown()  override;

    // C++ TODO: Most Java annotations will not have direct C++ equivalents:
    // ORIGINAL LINE: @Test public void testMe()
    virtual void testMe();

  protected:
    std::shared_ptr<NestedTeardownChain> shared_from_this()
    {
      return std::static_pointer_cast<NestedTeardownChain>(
          AbstractNestedTest::shared_from_this());
    }
  };

public:
  TestSetupTeardownChaining();

  /**
   * Verify super method calls on {@link LuceneTestCase#setUp()}.
   */
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testSetupChaining()
  virtual void testSetupChaining();

  /**
   * Verify super method calls on {@link LuceneTestCase#tearDown()}.
   */
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testTeardownChaining()
  virtual void testTeardownChaining();

protected:
  std::shared_ptr<TestSetupTeardownChaining> shared_from_this()
  {
    return std::static_pointer_cast<TestSetupTeardownChaining>(
        WithNestedTests::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/util/
