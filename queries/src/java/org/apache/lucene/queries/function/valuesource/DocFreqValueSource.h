#pragma once
#include "stringhelper.h"
#include <any>
#include <memory>
#include <string>
#include <unordered_map>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/queries/function/ValueSource.h"

#include  "core/src/java/org/apache/lucene/util/BytesRef.h"
#include  "core/src/java/org/apache/lucene/index/LeafReaderContext.h"
#include  "core/src/java/org/apache/lucene/queries/function/FunctionValues.h"
#include  "core/src/java/org/apache/lucene/search/IndexSearcher.h"

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
namespace org::apache::lucene::queries::function::valuesource
{

using LeafReaderContext = org::apache::lucene::index::LeafReaderContext;
using FunctionValues = org::apache::lucene::queries::function::FunctionValues;
using ValueSource = org::apache::lucene::queries::function::ValueSource;
using DoubleDocValues =
    org::apache::lucene::queries::function::docvalues::DoubleDocValues;
using IntDocValues =
    org::apache::lucene::queries::function::docvalues::IntDocValues;
using IndexSearcher = org::apache::lucene::search::IndexSearcher;
using BytesRef = org::apache::lucene::util::BytesRef;

class ConstIntDocValues : public IntDocValues
{
  GET_CLASS_NAME(ConstIntDocValues)
public:
  const int ival;
  const float fval;
  const double dval;
  const int64_t lval;
  const std::wstring sval;
  const std::shared_ptr<ValueSource> parent;

  // C++ TODO: There is no native C++ equivalent to 'toString':
  ConstIntDocValues(int val, std::shared_ptr<ValueSource> parent);

  float floatVal(int doc) override;
  int intVal(int doc) override;
  int64_t longVal(int doc) override;
  double doubleVal(int doc) override;
  std::wstring strVal(int doc) override;
  std::wstring toString(int doc) override;

protected:
  std::shared_ptr<ConstIntDocValues> shared_from_this()
  {
    return std::static_pointer_cast<ConstIntDocValues>(
        org.apache.lucene.queries.function.docvalues
            .IntDocValues::shared_from_this());
  }
};

class ConstDoubleDocValues : public DoubleDocValues
{
  GET_CLASS_NAME(ConstDoubleDocValues)
public:
  const int ival;
  const float fval;
  const double dval;
  const int64_t lval;
  const std::wstring sval;
  const std::shared_ptr<ValueSource> parent;

  // C++ TODO: There is no native C++ equivalent to 'toString':
  ConstDoubleDocValues(double val, std::shared_ptr<ValueSource> parent);

  float floatVal(int doc) override;
  int intVal(int doc) override;
  int64_t longVal(int doc) override;
  double doubleVal(int doc) override;
  std::wstring strVal(int doc) override;
  std::wstring toString(int doc) override;

protected:
  std::shared_ptr<ConstDoubleDocValues> shared_from_this()
  {
    return std::static_pointer_cast<ConstDoubleDocValues>(
        org.apache.lucene.queries.function.docvalues
            .DoubleDocValues::shared_from_this());
  }
};

/**
 * <code>DocFreqValueSource</code> returns the number of documents containing
 * the term.
 * @lucene.internal
 */
class DocFreqValueSource : public ValueSource
{
  GET_CLASS_NAME(DocFreqValueSource)
protected:
  const std::wstring field;
  const std::wstring indexedField;
  const std::wstring val;
  const std::shared_ptr<BytesRef> indexedBytes;

public:
  DocFreqValueSource(const std::wstring &field, const std::wstring &val,
                     const std::wstring &indexedField,
                     std::shared_ptr<BytesRef> indexedBytes);

  virtual std::wstring name();

  std::wstring description() override;

  std::shared_ptr<FunctionValues>
  getValues(std::unordered_map context,
            std::shared_ptr<LeafReaderContext> readerContext) 
      override;

  void createWeight(
      std::unordered_map context,
      std::shared_ptr<IndexSearcher> searcher)  override;

  virtual int hashCode();

  virtual bool equals(std::any o);

protected:
  std::shared_ptr<DocFreqValueSource> shared_from_this()
  {
    return std::static_pointer_cast<DocFreqValueSource>(
        org.apache.lucene.queries.function.ValueSource::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/queries/function/valuesource/
