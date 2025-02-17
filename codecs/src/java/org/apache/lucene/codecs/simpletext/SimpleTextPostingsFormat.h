#pragma once
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/PostingsFormat.h"
#include "stringhelper.h"
#include <memory>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/codecs/FieldsConsumer.h"

#include  "core/src/java/org/apache/lucene/index/SegmentWriteState.h"
#include  "core/src/java/org/apache/lucene/codecs/FieldsProducer.h"
#include  "core/src/java/org/apache/lucene/index/SegmentReadState.h"

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
namespace org::apache::lucene::codecs::simpletext
{

using FieldsConsumer = org::apache::lucene::codecs::FieldsConsumer;
using FieldsProducer = org::apache::lucene::codecs::FieldsProducer;
using PostingsFormat = org::apache::lucene::codecs::PostingsFormat;
using SegmentReadState = org::apache::lucene::index::SegmentReadState;
using SegmentWriteState = org::apache::lucene::index::SegmentWriteState;

/** For debugging, curiosity, transparency only!!  Do not
 *  use this codec in production.
 *
 *  <p>This codec stores all postings data in a single
 *  human-readable text file (_N.pst).  You can view this in
 *  any text editor, and even edit it to alter your index.
 *
 *  @lucene.experimental */
class SimpleTextPostingsFormat final : public PostingsFormat
{
  GET_CLASS_NAME(SimpleTextPostingsFormat)

public:
  SimpleTextPostingsFormat();

  std::shared_ptr<FieldsConsumer> fieldsConsumer(
      std::shared_ptr<SegmentWriteState> state)  override;

  std::shared_ptr<FieldsProducer> fieldsProducer(
      std::shared_ptr<SegmentReadState> state)  override;

  /** Extension of freq postings file */
  static const std::wstring POSTINGS_EXTENSION;

  static std::wstring getPostingsFileName(const std::wstring &segment,
                                          const std::wstring &segmentSuffix);

protected:
  std::shared_ptr<SimpleTextPostingsFormat> shared_from_this()
  {
    return std::static_pointer_cast<SimpleTextPostingsFormat>(
        org.apache.lucene.codecs.PostingsFormat::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/codecs/simpletext/
