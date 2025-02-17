using namespace std;

#include "TestBasics.h"

namespace org::apache::lucene::search::spans
{
using namespace org::apache::lucene::analysis;
using Document = org::apache::lucene::document::Document;
using Field = org::apache::lucene::document::Field;
using IndexReader = org::apache::lucene::index::IndexReader;
using RandomIndexWriter = org::apache::lucene::index::RandomIndexWriter;
using Term = org::apache::lucene::index::Term;
using BooleanClause = org::apache::lucene::search::BooleanClause;
using BooleanQuery = org::apache::lucene::search::BooleanQuery;
using CheckHits = org::apache::lucene::search::CheckHits;
using IndexSearcher = org::apache::lucene::search::IndexSearcher;
using PhraseQuery = org::apache::lucene::search::PhraseQuery;
using Query = org::apache::lucene::search::Query;
using TermQuery = org::apache::lucene::search::TermQuery;
using Directory = org::apache::lucene::store::Directory;
using English = org::apache::lucene::util::English;
using LuceneTestCase = org::apache::lucene::util::LuceneTestCase;
using TestUtil = org::apache::lucene::util::TestUtil;
using org::junit::AfterClass;
using org::junit::BeforeClass;
using namespace org::apache::lucene::search::spans;
//    import static org.apache.lucene.search.spans.SpanTestUtil.*;
shared_ptr<org::apache::lucene::search::IndexSearcher> TestBasics::searcher;
shared_ptr<org::apache::lucene::index::IndexReader> TestBasics::reader;
shared_ptr<org::apache::lucene::store::Directory> TestBasics::directory;

// C++ TODO: Most Java annotations will not have direct C++ equivalents:
// ORIGINAL LINE: @BeforeClass public static void beforeClass() throws Exception
void TestBasics::beforeClass() 
{
  directory = newDirectory();
  shared_ptr<RandomIndexWriter> writer = make_shared<RandomIndexWriter>(
      random(), directory,
      newIndexWriterConfig(
          make_shared<MockAnalyzer>(random(), MockTokenizer::SIMPLE, true))
          ->setMaxBufferedDocs(TestUtil::nextInt(random(), 100, 1000))
          ->setMergePolicy(newLogMergePolicy()));
  // writer.infoStream = System.out;
  for (int i = 0; i < 2000; i++) {
    shared_ptr<Document> doc = make_shared<Document>();
    doc->push_back(
        newTextField(L"field", English::intToEnglish(i), Field::Store::YES));
    writer->addDocument(doc);
  }
  reader = writer->getReader();
  searcher = newSearcher(reader);
  delete writer;
}

// C++ TODO: Most Java annotations will not have direct C++ equivalents:
// ORIGINAL LINE: @AfterClass public static void afterClass() throws Exception
void TestBasics::afterClass() 
{
  delete reader;
  delete directory;
  searcher.reset();
  reader.reset();
  directory.reset();
}

void TestBasics::testTerm() 
{
  shared_ptr<Query> query =
      make_shared<TermQuery>(make_shared<Term>(L"field", L"seventy"));
  checkHits(query,
            std::deque<int>{
                70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
                170,  171,  172,  173,  174,  175,  176,  177,  178,  179,
                270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
                370,  371,  372,  373,  374,  375,  376,  377,  378,  379,
                470,  471,  472,  473,  474,  475,  476,  477,  478,  479,
                570,  571,  572,  573,  574,  575,  576,  577,  578,  579,
                670,  671,  672,  673,  674,  675,  676,  677,  678,  679,
                770,  771,  772,  773,  774,  775,  776,  777,  778,  779,
                870,  871,  872,  873,  874,  875,  876,  877,  878,  879,
                970,  971,  972,  973,  974,  975,  976,  977,  978,  979,
                1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079,
                1170, 1171, 1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179,
                1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277, 1278, 1279,
                1370, 1371, 1372, 1373, 1374, 1375, 1376, 1377, 1378, 1379,
                1470, 1471, 1472, 1473, 1474, 1475, 1476, 1477, 1478, 1479,
                1570, 1571, 1572, 1573, 1574, 1575, 1576, 1577, 1578, 1579,
                1670, 1671, 1672, 1673, 1674, 1675, 1676, 1677, 1678, 1679,
                1770, 1771, 1772, 1773, 1774, 1775, 1776, 1777, 1778, 1779,
                1870, 1871, 1872, 1873, 1874, 1875, 1876, 1877, 1878, 1879,
                1970, 1971, 1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979});
}

void TestBasics::testTerm2() 
{
  shared_ptr<Query> query =
      make_shared<TermQuery>(make_shared<Term>(L"field", L"seventish"));
  checkHits(query, std::deque<int>());
}

void TestBasics::testPhrase() 
{
  shared_ptr<PhraseQuery> query =
      make_shared<PhraseQuery>(L"field", L"seventy", L"seven");
  checkHits(query, std::deque<int>{77,   177,  277,  377,  477,  577,  677,
                                    777,  877,  977,  1077, 1177, 1277, 1377,
                                    1477, 1577, 1677, 1777, 1877, 1977});
}

void TestBasics::testPhrase2() 
{
  shared_ptr<PhraseQuery> query =
      make_shared<PhraseQuery>(L"field", L"seventish", L"sevenon");
  checkHits(query, std::deque<int>());
}

void TestBasics::testBoolean() 
{
  shared_ptr<BooleanQuery::Builder> query =
      make_shared<BooleanQuery::Builder>();
  query->add(make_shared<TermQuery>(make_shared<Term>(L"field", L"seventy")),
             BooleanClause::Occur::MUST);
  query->add(make_shared<TermQuery>(make_shared<Term>(L"field", L"seven")),
             BooleanClause::Occur::MUST);
  checkHits(query->build(),
            std::deque<int>{77,   177,  277,  377,  477,  577,  677,  770,
                             771,  772,  773,  774,  775,  776,  777,  778,
                             779,  877,  977,  1077, 1177, 1277, 1377, 1477,
                             1577, 1677, 1770, 1771, 1772, 1773, 1774, 1775,
                             1776, 1777, 1778, 1779, 1877, 1977});
}

void TestBasics::testBoolean2() 
{
  shared_ptr<BooleanQuery::Builder> query =
      make_shared<BooleanQuery::Builder>();
  query->add(make_shared<TermQuery>(make_shared<Term>(L"field", L"sevento")),
             BooleanClause::Occur::MUST);
  query->add(make_shared<TermQuery>(make_shared<Term>(L"field", L"sevenly")),
             BooleanClause::Occur::MUST);
  checkHits(query->build(), std::deque<int>());
}

void TestBasics::testSpanNearExact() 
{
  shared_ptr<SpanQuery> query =
      spanNearOrderedQuery(L"field", 0, L"seventy", L"seven");

  checkHits(query, std::deque<int>{77,   177,  277,  377,  477,  577,  677,
                                    777,  877,  977,  1077, 1177, 1277, 1377,
                                    1477, 1577, 1677, 1777, 1877, 1977});

  assertTrue(searcher->explain(query, 77)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 977)->getValue() > 0.0f);
}

void TestBasics::testSpanTermQuery() 
{
  checkHits(SpanTestUtil::spanTermQuery(L"field", L"seventy"),
            std::deque<int>{
                70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
                170,  171,  172,  173,  174,  175,  176,  177,  178,  179,
                270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
                370,  371,  372,  373,  374,  375,  376,  377,  378,  379,
                470,  471,  472,  473,  474,  475,  476,  477,  478,  479,
                570,  571,  572,  573,  574,  575,  576,  577,  578,  579,
                670,  671,  672,  673,  674,  675,  676,  677,  678,  679,
                770,  771,  772,  773,  774,  775,  776,  777,  778,  779,
                870,  871,  872,  873,  874,  875,  876,  877,  878,  879,
                970,  971,  972,  973,  974,  975,  976,  977,  978,  979,
                1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079,
                1170, 1270, 1370, 1470, 1570, 1670, 1770, 1870, 1970, 1171,
                1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179, 1271, 1272,
                1273, 1274, 1275, 1276, 1277, 1278, 1279, 1371, 1372, 1373,
                1374, 1375, 1376, 1377, 1378, 1379, 1471, 1472, 1473, 1474,
                1475, 1476, 1477, 1478, 1479, 1571, 1572, 1573, 1574, 1575,
                1576, 1577, 1578, 1579, 1671, 1672, 1673, 1674, 1675, 1676,
                1677, 1678, 1679, 1771, 1772, 1773, 1774, 1775, 1776, 1777,
                1778, 1779, 1871, 1872, 1873, 1874, 1875, 1876, 1877, 1878,
                1879, 1971, 1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979});
}

void TestBasics::testSpanNearUnordered() 
{
  checkHits(spanNearUnorderedQuery(L"field", 4, L"nine", L"six"),
            std::deque<int>{609,  629,  639,  649,  659,  669,  679,  689,
                             699,  906,  926,  936,  946,  956,  966,  976,
                             986,  996,  1609, 1629, 1639, 1649, 1659, 1669,
                             1679, 1689, 1699, 1906, 1926, 1936, 1946, 1956,
                             1966, 1976, 1986, 1996});
}

void TestBasics::testSpanNearOrdered() 
{
  checkHits(spanNearOrderedQuery(L"field", 4, L"nine", L"six"),
            std::deque<int>{906, 926, 936, 946, 956, 966, 976, 986, 996, 1906,
                             1926, 1936, 1946, 1956, 1966, 1976, 1986, 1996});
}

void TestBasics::testSpanNot() 
{
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"one");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(
      near, SpanTestUtil::spanTermQuery(L"field", L"forty"));

  checkHits(query,
            std::deque<int>{801, 821, 831, 851, 861, 871, 881, 891, 1801, 1821,
                             1831, 1851, 1861, 1871, 1881, 1891});

  assertTrue(searcher->explain(query, 801)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 891)->getValue() > 0.0f);
}

void TestBasics::testSpanNotNoOverflowOnLargeSpans() 
{
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"one");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(
      near, SpanTestUtil::spanTermQuery(L"field", L"forty"),
      numeric_limits<int>::max(), numeric_limits<int>::max());

  checkHits(query,
            std::deque<int>{801, 821, 831, 851, 861, 871, 881, 891, 1801, 1821,
                             1831, 1851, 1861, 1871, 1881, 1891});
}

void TestBasics::testSpanWithMultipleNotSingle() 
{
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"one");
  shared_ptr<SpanQuery> or = SpanTestUtil::spanOrQuery(L"field", {L"forty"});
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(near, or);

  checkHits(query,
            std::deque<int>{801, 821, 831, 851, 861, 871, 881, 891, 1801, 1821,
                             1831, 1851, 1861, 1871, 1881, 1891});

  assertTrue(searcher->explain(query, 801)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 891)->getValue() > 0.0f);
}

void TestBasics::testSpanWithMultipleNotMany() 
{
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"one");
  shared_ptr<SpanQuery> or
      = spanOrQuery(L"field", L"forty", L"sixty", L"eighty");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(near, or);

  checkHits(query, std::deque<int>{801, 821, 831, 851, 871, 891, 1801, 1821,
                                    1831, 1851, 1871, 1891});

  assertTrue(searcher->explain(query, 801)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 891)->getValue() > 0.0f);
}

void TestBasics::testNpeInSpanNearWithSpanNot() 
{
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"one");
  shared_ptr<SpanQuery> exclude =
      spanNearOrderedQuery(L"field", 1, L"hundred", L"forty");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(near, exclude);

  checkHits(query,
            std::deque<int>{801, 821, 831, 851, 861, 871, 881, 891, 1801, 1821,
                             1831, 1851, 1861, 1871, 1881, 1891});

  assertTrue(searcher->explain(query, 801)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 891)->getValue() > 0.0f);
}

void TestBasics::testNpeInSpanNearInSpanFirstInSpanNot() 
{
  constexpr int n = 5;
  shared_ptr<SpanQuery> include = SpanTestUtil::spanFirstQuery(
      SpanTestUtil::spanTermQuery(L"field", L"forty"), n);
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", n - 1, L"hundred", L"forty");
  shared_ptr<SpanQuery> exclude = SpanTestUtil::spanFirstQuery(near, n - 1);
  shared_ptr<SpanQuery> q = SpanTestUtil::spanNotQuery(include, exclude);

  checkHits(q, std::deque<int>{
                   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,
                   1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049,
                   1140, 1141, 1142, 1143, 1144, 1145, 1146, 1147, 1148, 1149,
                   1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1248, 1249,
                   1340, 1341, 1342, 1343, 1344, 1345, 1346, 1347, 1348, 1349,
                   1440, 1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449,
                   1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547, 1548, 1549,
                   1640, 1641, 1642, 1643, 1644, 1645, 1646, 1647, 1648, 1649,
                   1740, 1741, 1742, 1743, 1744, 1745, 1746, 1747, 1748, 1749,
                   1840, 1841, 1842, 1843, 1844, 1845, 1846, 1847, 1848, 1849,
                   1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1949});
}

void TestBasics::testSpanNotWindowOne() 
{
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"forty");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(
      near, SpanTestUtil::spanTermQuery(L"field", L"one"), 1, 1);

  checkHits(query,
            std::deque<int>{840, 842, 843, 844, 845, 846, 847, 848, 849, 1840,
                             1842, 1843, 1844, 1845, 1846, 1847, 1848, 1849});

  assertTrue(searcher->explain(query, 840)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 1842)->getValue() > 0.0f);
}

void TestBasics::testSpanNotWindowTwoBefore() 
{
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"forty");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(
      near, SpanTestUtil::spanTermQuery(L"field", L"one"), 2, 0);

  checkHits(query,
            std::deque<int>{840, 841, 842, 843, 844, 845, 846, 847, 848, 849});

  assertTrue(searcher->explain(query, 840)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 849)->getValue() > 0.0f);
}

void TestBasics::testSpanNotWindowNegPost() 
{
  // test handling of invalid window < 0
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"one");
  shared_ptr<SpanQuery> or = SpanTestUtil::spanOrQuery(L"field", {L"forty"});
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(near, or, 0, -1);
  checkHits(query,
            std::deque<int>{801, 821, 831, 851, 861, 871, 881, 891, 1801, 1821,
                             1831, 1851, 1861, 1871, 1881, 1891});

  query = SpanTestUtil::spanNotQuery(near, or, 0, -2);
  checkHits(query,
            std::deque<int>{801, 821, 831, 841, 851, 861, 871, 881, 891, 1801,
                             1821, 1831, 1841, 1851, 1861, 1871, 1881, 1891});

  assertTrue(searcher->explain(query, 801)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 891)->getValue() > 0.0f);
}

void TestBasics::testSpanNotWindowNegPre() 
{
  // test handling of invalid window < 0
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 4, L"eight", L"one");
  shared_ptr<SpanQuery> or = SpanTestUtil::spanOrQuery(L"field", {L"forty"});
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(near, or, -2, 0);
  checkHits(query,
            std::deque<int>{801, 821, 831, 851, 861, 871, 881, 891, 1801, 1821,
                             1831, 1851, 1861, 1871, 1881, 1891});

  query = SpanTestUtil::spanNotQuery(near, or, -3, 0);
  checkHits(query,
            std::deque<int>{801, 821, 831, 841, 851, 861, 871, 881, 891, 1801,
                             1821, 1831, 1841, 1851, 1861, 1871, 1881, 1891});

  assertTrue(searcher->explain(query, 801)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 891)->getValue() > 0.0f);
}

void TestBasics::testSpanNotWindowDoubleExcludesBefore() 
{
  // test hitting two excludes before an include
  shared_ptr<SpanQuery> near =
      spanNearOrderedQuery(L"field", 2, L"forty", L"two");
  shared_ptr<SpanQuery> exclude = SpanTestUtil::spanTermQuery(L"field", L"one");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanNotQuery(near, exclude, 4, 1);

  checkHits(query,
            std::deque<int>{42, 242, 342, 442, 542, 642, 742, 842, 942});

  assertTrue(searcher->explain(query, 242)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 942)->getValue() > 0.0f);
}

void TestBasics::testSpanFirst() 
{
  shared_ptr<SpanQuery> query = SpanTestUtil::spanFirstQuery(
      SpanTestUtil::spanTermQuery(L"field", L"five"), 1);

  checkHits(query,
            std::deque<int>{
                5,   500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511,
                512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524,
                525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537,
                538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550,
                551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563,
                564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576,
                577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589,
                590, 591, 592, 593, 594, 595, 596, 597, 598, 599});

  assertTrue(searcher->explain(query, 5)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 599)->getValue() > 0.0f);
}

void TestBasics::testSpanPositionRange() 
{
  shared_ptr<SpanQuery> term1 = SpanTestUtil::spanTermQuery(L"field", L"five");
  shared_ptr<SpanQuery> query =
      SpanTestUtil::spanPositionRangeQuery(term1, 1, 2);

  checkHits(query, std::deque<int>{25, 35, 45, 55, 65, 75, 85, 95});
  assertTrue(searcher->explain(query, 25)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 95)->getValue() > 0.0f);

  query = SpanTestUtil::spanPositionRangeQuery(term1, 0, 1);
  checkHits(query,
            std::deque<int>{
                5,   500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511,
                512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524,
                525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537,
                538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550,
                551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563,
                564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576,
                577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589,
                590, 591, 592, 593, 594, 595, 596, 597, 598, 599});

  query = SpanTestUtil::spanPositionRangeQuery(term1, 6, 7);
  checkHits(query, std::deque<int>());
}

void TestBasics::testSpanOr() 
{
  shared_ptr<SpanQuery> near1 =
      spanNearOrderedQuery(L"field", 0, L"thirty", L"three");
  shared_ptr<SpanQuery> near2 =
      spanNearOrderedQuery(L"field", 0, L"forty", L"seven");
  shared_ptr<SpanQuery> query = SpanTestUtil::spanOrQuery({near1, near2});

  checkHits(query,
            std::deque<int>{33,   47,   133,  147,  233,  247,  333,  347,
                             433,  447,  533,  547,  633,  647,  733,  747,
                             833,  847,  933,  947,  1033, 1047, 1133, 1147,
                             1233, 1247, 1333, 1347, 1433, 1447, 1533, 1547,
                             1633, 1647, 1733, 1747, 1833, 1847, 1933, 1947});

  assertTrue(searcher->explain(query, 33)->getValue() > 0.0f);
  assertTrue(searcher->explain(query, 947)->getValue() > 0.0f);
}

void TestBasics::testSpanExactNested() 
{
  shared_ptr<SpanQuery> near1 =
      spanNearOrderedQuery(L"field", 0, L"three", L"hundred");
  shared_ptr<SpanQuery> near2 =
      spanNearOrderedQuery(L"field", 0, L"thirty", L"three");
  shared_ptr<SpanQuery> query =
      SpanTestUtil::spanNearOrderedQuery(0, {near1, near2});

  checkHits(query, std::deque<int>{333, 1333});

  assertTrue(searcher->explain(query, 333)->getValue() > 0.0f);
}

void TestBasics::testSpanNearOr() 
{
  shared_ptr<SpanQuery> to1 = spanOrQuery(L"field", L"six", L"seven");
  shared_ptr<SpanQuery> to2 = spanOrQuery(L"field", L"seven", L"six");
  shared_ptr<SpanQuery> query =
      SpanTestUtil::spanNearOrderedQuery(10, {to1, to2});

  checkHits(query, std::deque<int>{
                       606,  607,  626,  627,  636,  637,  646,  647,  656,
                       657,  666,  667,  676,  677,  686,  687,  696,  697,
                       706,  707,  726,  727,  736,  737,  746,  747,  756,
                       757,  766,  767,  776,  777,  786,  787,  796,  797,
                       1606, 1607, 1626, 1627, 1636, 1637, 1646, 1647, 1656,
                       1657, 1666, 1667, 1676, 1677, 1686, 1687, 1696, 1697,
                       1706, 1707, 1726, 1727, 1736, 1737, 1746, 1747, 1756,
                       1757, 1766, 1767, 1776, 1777, 1786, 1787, 1796, 1797});
}

void TestBasics::testSpanComplex1() 
{
  shared_ptr<SpanQuery> tt1 =
      spanNearOrderedQuery(L"field", 0, L"six", L"hundred");
  shared_ptr<SpanQuery> tt2 =
      spanNearOrderedQuery(L"field", 0, L"seven", L"hundred");

  shared_ptr<SpanQuery> to1 = SpanTestUtil::spanOrQuery({tt1, tt2});
  shared_ptr<SpanQuery> to2 = spanOrQuery(L"field", L"seven", L"six");
  shared_ptr<SpanQuery> query =
      SpanTestUtil::spanNearOrderedQuery(100, {to1, to2});

  checkHits(query, std::deque<int>{
                       606,  607,  626,  627,  636,  637,  646,  647,  656,
                       657,  666,  667,  676,  677,  686,  687,  696,  697,
                       706,  707,  726,  727,  736,  737,  746,  747,  756,
                       757,  766,  767,  776,  777,  786,  787,  796,  797,
                       1606, 1607, 1626, 1627, 1636, 1637, 1646, 1647, 1656,
                       1657, 1666, 1667, 1676, 1677, 1686, 1687, 1696, 1697,
                       1706, 1707, 1726, 1727, 1736, 1737, 1746, 1747, 1756,
                       1757, 1766, 1767, 1776, 1777, 1786, 1787, 1796, 1797});
}

void TestBasics::checkHits(shared_ptr<Query> query,
                           std::deque<int> &results) 
{
  CheckHits::checkHits(random(), query, L"field", searcher, results);
}
} // namespace org::apache::lucene::search::spans