#pragma once
#include "stringhelper.h"
#include <memory>
#include <deque>

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
namespace org::apache::lucene::queries::function::docvalues
{

using LuceneTestCase = org::apache::lucene::util::LuceneTestCase;

/**
 * <p>
 * Sanity check that {@link FunctionValues#boolVal} behaves as expected for
 * trivial subclasses of the various (Numeric) DocValue implementations.
 * </p>
 * <p>
 * Any "non-zero" value should result in "true"
 * </p>
 */
class TestBoolValOfNumericDVs : public LuceneTestCase
{
  GET_CLASS_NAME(TestBoolValOfNumericDVs)

public:
  virtual void test() ;

  virtual void check(bool const expected) ;

protected:
  std::shared_ptr<TestBoolValOfNumericDVs> shared_from_this()
  {
    return std::static_pointer_cast<TestBoolValOfNumericDVs>(
        org.apache.lucene.util.LuceneTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/queries/function/docvalues/
