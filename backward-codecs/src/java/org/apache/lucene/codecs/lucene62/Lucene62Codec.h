#pragma once
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/Codec.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/lucene50/Lucene50CompoundFormat.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/lucene50/Lucene50LiveDocsFormat.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/lucene50/Lucene50StoredFieldsFormat.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/lucene50/Lucene50TermVectorsFormat.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/lucene60/Lucene60FieldInfosFormat.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/lucene62/Lucene62SegmentInfoFormat.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/perfield/PerFieldDocValuesFormat.h"
#include "../../../../../../../../core/src/java/org/apache/lucene/codecs/perfield/PerFieldPostingsFormat.h"
#include "../lucene53/Lucene53NormsFormat.h"
#include "stringhelper.h"
#include <memory>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/codecs/TermVectorsFormat.h"

#include  "core/src/java/org/apache/lucene/codecs/FieldInfosFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/SegmentInfoFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/LiveDocsFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/CompoundFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/PostingsFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/DocValuesFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/StoredFieldsFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/lucene50/Lucene50StoredFieldsFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/PointsFormat.h"
#include  "core/src/java/org/apache/lucene/codecs/NormsFormat.h"

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
namespace org::apache::lucene::codecs::lucene62
{

using Codec = org::apache::lucene::codecs::Codec;
using CompoundFormat = org::apache::lucene::codecs::CompoundFormat;
using DocValuesFormat = org::apache::lucene::codecs::DocValuesFormat;
using FieldInfosFormat = org::apache::lucene::codecs::FieldInfosFormat;
using LiveDocsFormat = org::apache::lucene::codecs::LiveDocsFormat;
using NormsFormat = org::apache::lucene::codecs::NormsFormat;
using PointsFormat = org::apache::lucene::codecs::PointsFormat;
using PostingsFormat = org::apache::lucene::codecs::PostingsFormat;
using SegmentInfoFormat = org::apache::lucene::codecs::SegmentInfoFormat;
using StoredFieldsFormat = org::apache::lucene::codecs::StoredFieldsFormat;
using TermVectorsFormat = org::apache::lucene::codecs::TermVectorsFormat;
using Lucene50CompoundFormat =
    org::apache::lucene::codecs::lucene50::Lucene50CompoundFormat;
using Lucene50LiveDocsFormat =
    org::apache::lucene::codecs::lucene50::Lucene50LiveDocsFormat;
using Lucene50StoredFieldsFormat =
    org::apache::lucene::codecs::lucene50::Lucene50StoredFieldsFormat;
using Lucene50TermVectorsFormat =
    org::apache::lucene::codecs::lucene50::Lucene50TermVectorsFormat;
using Mode =
    org::apache::lucene::codecs::lucene50::Lucene50StoredFieldsFormat::Mode;
using Lucene53NormsFormat =
    org::apache::lucene::codecs::lucene53::Lucene53NormsFormat;
using Lucene60FieldInfosFormat =
    org::apache::lucene::codecs::lucene60::Lucene60FieldInfosFormat;

/**
 * Implements the Lucene 6.2 index format, with configurable per-field postings
 * and docvalues formats.
 * <p>
 * If you want to reuse functionality of this codec in another codec, extend
 * {@link FilterCodec}.
 *
 * @see org.apache.lucene.codecs.lucene60 package documentation for file format
 * details.
 *
 * @lucene.experimental
 */
class Lucene62Codec : public Codec
{
  GET_CLASS_NAME(Lucene62Codec)
private:
  const std::shared_ptr<TermVectorsFormat> vectorsFormat =
      std::make_shared<Lucene50TermVectorsFormat>();
  // C++ NOTE: Fields cannot have the same name as methods:
  const std::shared_ptr<FieldInfosFormat> fieldInfosFormat_ =
      std::make_shared<Lucene60FieldInfosFormat>();
  const std::shared_ptr<SegmentInfoFormat> segmentInfosFormat =
      std::make_shared<Lucene62SegmentInfoFormat>();
  // C++ NOTE: Fields cannot have the same name as methods:
  const std::shared_ptr<LiveDocsFormat> liveDocsFormat_ =
      std::make_shared<Lucene50LiveDocsFormat>();
  // C++ NOTE: Fields cannot have the same name as methods:
  const std::shared_ptr<CompoundFormat> compoundFormat_ =
      std::make_shared<Lucene50CompoundFormat>();

  const std::shared_ptr<PostingsFormat> postingsFormat =
      std::make_shared<PerFieldPostingsFormatAnonymousInnerClass>();

private:
  class PerFieldPostingsFormatAnonymousInnerClass
      : public PerFieldPostingsFormat
  {
    GET_CLASS_NAME(PerFieldPostingsFormatAnonymousInnerClass)
  public:
    PerFieldPostingsFormatAnonymousInnerClass();

    std::shared_ptr<PostingsFormat>
    getPostingsFormatForField(const std::wstring &field) override;

  protected:
    std::shared_ptr<PerFieldPostingsFormatAnonymousInnerClass>
    shared_from_this()
    {
      return std::static_pointer_cast<
          PerFieldPostingsFormatAnonymousInnerClass>(
          org.apache.lucene.codecs.perfield
              .PerFieldPostingsFormat::shared_from_this());
    }
  };

private:
  const std::shared_ptr<DocValuesFormat> docValuesFormat =
      std::make_shared<PerFieldDocValuesFormatAnonymousInnerClass>();

private:
  class PerFieldDocValuesFormatAnonymousInnerClass
      : public PerFieldDocValuesFormat
  {
    GET_CLASS_NAME(PerFieldDocValuesFormatAnonymousInnerClass)
  public:
    PerFieldDocValuesFormatAnonymousInnerClass();

    std::shared_ptr<DocValuesFormat>
    getDocValuesFormatForField(const std::wstring &field) override;

  protected:
    std::shared_ptr<PerFieldDocValuesFormatAnonymousInnerClass>
    shared_from_this()
    {
      return std::static_pointer_cast<
          PerFieldDocValuesFormatAnonymousInnerClass>(
          org.apache.lucene.codecs.perfield
              .PerFieldDocValuesFormat::shared_from_this());
    }
  };

private:
  // C++ NOTE: Fields cannot have the same name as methods:
  const std::shared_ptr<StoredFieldsFormat> storedFieldsFormat_;

  /**
   * Instantiates a new codec.
   */
public:
  Lucene62Codec();

  /**
   * Instantiates a new codec, specifying the stored fields compression
   * mode to use.
   * @param mode stored fields compression mode to use for newly
   *             flushed/merged segments.
   */
  Lucene62Codec(Lucene50StoredFieldsFormat::Mode mode);

  std::shared_ptr<StoredFieldsFormat> storedFieldsFormat() override final;

  std::shared_ptr<TermVectorsFormat> termVectorsFormat() override final;

  std::shared_ptr<PostingsFormat> postingsFormat() override final;

  std::shared_ptr<FieldInfosFormat> fieldInfosFormat() override final;

  std::shared_ptr<SegmentInfoFormat> segmentInfoFormat() override;

  std::shared_ptr<LiveDocsFormat> liveDocsFormat() override final;

  std::shared_ptr<CompoundFormat> compoundFormat() override final;

  std::shared_ptr<PointsFormat> pointsFormat() override final;

  /** Returns the postings format that should be used for writing
   *  new segments of <code>field</code>.
   *
   *  The default implementation always returns "Lucene50".
   *  <p>
   *  <b>WARNING:</b> if you subclass, you are responsible for index
   *  backwards compatibility: future version of Lucene are only
   *  guaranteed to be able to read the default implementation.
   */
  virtual std::shared_ptr<PostingsFormat>
  getPostingsFormatForField(const std::wstring &field);

  /** Returns the docvalues format that should be used for writing
   *  new segments of <code>field</code>.
   *
   *  The default implementation always returns "Lucene54".
   *  <p>
   *  <b>WARNING:</b> if you subclass, you are responsible for index
   *  backwards compatibility: future version of Lucene are only
   *  guaranteed to be able to read the default implementation.
   */
  virtual std::shared_ptr<DocValuesFormat>
  getDocValuesFormatForField(const std::wstring &field);

  std::shared_ptr<DocValuesFormat> docValuesFormat() override final;

private:
  const std::shared_ptr<PostingsFormat> defaultFormat =
      PostingsFormat::forName(L"Lucene50");
  const std::shared_ptr<DocValuesFormat> defaultDVFormat =
      DocValuesFormat::forName(L"Lucene54");

  // C++ NOTE: Fields cannot have the same name as methods:
  const std::shared_ptr<NormsFormat> normsFormat_ =
      std::make_shared<Lucene53NormsFormat>();

public:
  std::shared_ptr<NormsFormat> normsFormat() override;

protected:
  std::shared_ptr<Lucene62Codec> shared_from_this()
  {
    return std::static_pointer_cast<Lucene62Codec>(
        org.apache.lucene.codecs.Codec::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/codecs/lucene62/
