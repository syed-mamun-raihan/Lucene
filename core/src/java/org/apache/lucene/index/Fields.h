#pragma once
#include "stringhelper.h"
#include <memory>
#include <string>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/index/Terms.h"

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
namespace org::apache::lucene::index
{

/**
 * Provides a {@link Terms} index for fields that have it, and lists which
 * fields do. This is primarily an internal/experimental API (see {@link
 * FieldsProducer}), although it is also used to expose the set of term vectors
 * per document.
 *
 * @lucene.experimental
 */
class Fields : public std::enable_shared_from_this<Fields>,
               public std::deque<std::wstring>
{
  GET_CLASS_NAME(Fields)

  /** Sole constructor. (For invocation by subclass
   *  constructors, typically implicit.) */
protected:
  Fields();

  /** Returns an iterator that will step through all fields
   *  names.  This will not return null.  */
public:
  std::shared_ptr<Iterator<std::wstring>> iterator() = 0;
  override

      /** Get the {@link Terms} for this field.  This will return
       *  null if the field does not exist. */
      virtual std::shared_ptr<Terms>
      terms(const std::wstring &field) = 0;

  /** Returns the number of fields or -1 if the number of
   * distinct field names is unknown. If &gt;= 0,
   * {@link #iterator} will return as many field names. */
  virtual int size() = 0;

  /** Zero-length {@code Fields} array. */
  static std::deque<std::shared_ptr<Fields>> const EMPTY_ARRAY;
};

} // #include  "core/src/java/org/apache/lucene/index/
