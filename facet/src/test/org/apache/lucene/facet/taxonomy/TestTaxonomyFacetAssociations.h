#pragma once
#include "stringhelper.h"
#include <memory>
#include <stdexcept>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/store/Directory.h"

#include  "core/src/java/org/apache/lucene/index/IndexReader.h"
#include  "core/src/java/org/apache/lucene/facet/taxonomy/TaxonomyReader.h"
#include  "core/src/java/org/apache/lucene/facet/FacetsConfig.h"

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
namespace org::apache::lucene::facet::taxonomy
{

using FacetTestCase = org::apache::lucene::facet::FacetTestCase;
using FacetsConfig = org::apache::lucene::facet::FacetsConfig;
using IndexReader = org::apache::lucene::index::IndexReader;
using Directory = org::apache::lucene::store::Directory;

/** Test for associations */
class TestTaxonomyFacetAssociations : public FacetTestCase
{
  GET_CLASS_NAME(TestTaxonomyFacetAssociations)

private:
  static std::shared_ptr<Directory> dir;
  static std::shared_ptr<IndexReader> reader;
  static std::shared_ptr<Directory> taxoDir;
  static std::shared_ptr<TaxonomyReader> taxoReader;

  static std::shared_ptr<FacetsConfig> config;

public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @BeforeClass public static void beforeClass() throws
  // Exception
  static void beforeClass() ;

  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @AfterClass public static void afterClass() throws Exception
  static void afterClass() ;

  virtual void testIntSumAssociation() ;

  virtual void testFloatSumAssociation() ;

  /** Make sure we can test both int and float assocs in one
   *  index, as long as we send each to a different field. */
  virtual void testIntAndFloatAssocation() ;

  virtual void testWrongIndexFieldName() ;

  virtual void testMixedTypesInSameIndexField() ;

  virtual void testNoHierarchy() ;

  virtual void testRequireDimCount() ;

  virtual void testIntSumAssociationDrillDown() ;

protected:
  std::shared_ptr<TestTaxonomyFacetAssociations> shared_from_this()
  {
    return std::static_pointer_cast<TestTaxonomyFacetAssociations>(
        org.apache.lucene.facet.FacetTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/facet/taxonomy/
