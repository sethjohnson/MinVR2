#include "config/VRDataIndex.h"

int testIndexSerialize();
int testIndexSerializeIntArray();
int testIndexSerializeIntArraySep();
int testIndexPrintDoubleArray();
int testIndexLotsaEntries();
int testPushPopIndex();
int testEscapedChars();
int testSelections();
int testLinkNode();
int testLinkContent();

// Make this a large number to get decent timing data.
#define LOOP for (int loopctr = 0; loopctr < 100; loopctr++)

int indextest(int argc, char* argv[]) {
  
  int defaultchoice = 1;
  
  int choice = defaultchoice;

  if (argc > 1) {
    if(sscanf(argv[1], "%d", &choice) != 1) {
      printf("Couldn't parse that input as a number\n");
      return -1;
    }
  }

  int output;
  
  switch(choice) {
  case 1:
    output = testIndexSerialize();
    break;
    
  case 2:
    output = testIndexSerializeIntArray();
    break;

  case 3:
    output = testIndexSerializeIntArraySep();
    break;

  case 4:
    output = testIndexPrintDoubleArray();
    break;

  case 5:
    output = testIndexLotsaEntries();
    break;

  case 6:
    output = testPushPopIndex();
    break;

  case 7:
    output = testEscapedChars();
    break;

  case 8:
    output = testSelections();
    break;

  case 9:
    output = testLinkNode();
    break;

  case 10:
    output = testLinkContent();
    break;
    
  default:
    std::cout << "Test #" << choice << " does not exist!\n";
    output = -1;
  }
  
  return output;
}

VRDataIndex * setupIndex() {

  VRDataIndex *n = new VRDataIndex;

  VRInt a = 4;
  VRDouble b = 3.1415926;
  
  n->addData("/george/a0", a);
  n->addData("/george/a1", a + 1);
  n->addData("/george/a2", a + 2);
  n->addData("/george/a3", a + 3);
  n->addData("/george/a4", a + 4);
  n->addData("/george/a5", a + 5);
  n->addData("/george/a6", a + 6);
  n->addData("/george/a7", a + 7);
  n->addData("/george/a8", a + 8);
  n->addData("/george/a9", a + 9);

  n->addData("/martha/b0", b);
  n->addData("/martha/b1", b * 1);
  n->addData("/martha/b2", b * 2);
  n->addData("/martha/b3", b * 3);
  n->addData("/martha/b4", b * 4);
  n->addData("/martha/b5", b * 5);
  n->addData("/martha/b6", b * 6);
  n->addData("/martha/b7", b * 7);
  n->addData("/martha/b8", b * 8);
  n->addData("/martha/b9", b * 9);

  VRString c = "abigail";
  n->addData("/john/c0", c + "0");
  n->addData("/john/c1", c + "1");
  n->addData("/john/c2", c + "2");
  n->addData("/john/c3", c + "3");
  n->addData("/john/c4", c + "4");
  n->addData("/john/c5", c + "5");
  n->addData("/john/c6", c + "6");
  n->addData("/john/c7", c + "7");
  n->addData("/john/c8", c + "8");
  n->addData("/john/c9", c + "9");

  std::vector<double>d;
  d.push_back(1.2);
  d.push_back(2.3);
  d.push_back(3.4);
  d.push_back(4.5);
  d.push_back(5.6);

  n->addData("/donna/d0", d);
  
  // This file is specified using the WORKING_DIRECTORY option in the
  // ctest framework.  See the CMakeLists.txt file in this directory,
  // and look for the add_test command.
  n->processXMLFile("test.xml", "/");
  
  return n;
}

int testSelections() {

  // Set up the test string and several expected outputs.
  std::string xmlteststring =  "<MVR><!-- some of the illegitimate children of John I --><John name=\"Lackland\"><Isabella name=\"Angouleme\"><Henry seq=\"III\" title=\"King\">1</Henry> <Richard title=\"Earl of Cornwall\">2</Richard> <Joan title=\"Queen Consort\">3</Joan> <Isabella title=\"Queen Consort\">4</Isabella> <Eleanor type=\"string\">5</Eleanor> </Isabella><Joan title=\"Lady of Wales\"><Richard name=\"FitzRoy\">6</Richard><Oliver name=\"FitzRoy\">7</Oliver></Joan> <Unknown><Geoffrey name=\"FitzRoy\" type=\"string\">8</Geoffrey><John name=\"FitzRoy\">9</John> <Henry name=\"FitzRoy\">10</Henry> <Osbert name=\"Gifford\">11</Osbert> <Eudes name=\"FitzRoy\">12</Eudes> <Bartholomew name=\"FitzRoy\">13</Bartholomew> <Maud name=\"FitzRoy\" title=\"Abbess of Barking\">14</Maud><Isabella name=\"FitzRoy\">15</Isabella><Philip name=\"FitzRoy\" type=\"string\">16</Philip></Unknown> </John></MVR>";
  
  VRContainer firstTestList;

  firstTestList.push_back("/MVR/John");
  firstTestList.push_back("/MVR/John/Isabella");
  firstTestList.push_back("/MVR/John/Joan/Oliver");
  firstTestList.push_back("/MVR/John/Joan/Richard");
  firstTestList.push_back("/MVR/John/Unknown/Bartholomew");
  firstTestList.push_back("/MVR/John/Unknown/Eudes");
  firstTestList.push_back("/MVR/John/Unknown/Geoffrey");
  firstTestList.push_back("/MVR/John/Unknown/Henry");
  firstTestList.push_back("/MVR/John/Unknown/Isabella");
  firstTestList.push_back("/MVR/John/Unknown/John");
  firstTestList.push_back("/MVR/John/Unknown/Maud");
  firstTestList.push_back("/MVR/John/Unknown/Osbert");
  firstTestList.push_back("/MVR/John/Unknown/Philip");
  
  VRContainer secondTestList;

  secondTestList.push_back("/MVR/John/Joan/Oliver");
  secondTestList.push_back("/MVR/John/Joan/Richard");
  secondTestList.push_back("/MVR/John/Unknown/Bartholomew");
  secondTestList.push_back("/MVR/John/Unknown/Eudes");
  secondTestList.push_back("/MVR/John/Unknown/Geoffrey");
  secondTestList.push_back("/MVR/John/Unknown/Henry");
  secondTestList.push_back("/MVR/John/Unknown/Isabella");
  secondTestList.push_back("/MVR/John/Unknown/John");
  secondTestList.push_back("/MVR/John/Unknown/Maud");
  secondTestList.push_back("/MVR/John/Unknown/Philip");

  VRContainer thirdTestList;

  thirdTestList.push_back("/MVR/John/Isabella/Eleanor");
  thirdTestList.push_back("/MVR/John/Unknown/Geoffrey");
  thirdTestList.push_back("/MVR/John/Unknown/Philip");
    
  VRContainer fourthTestList;

  fourthTestList.push_back("/MVR/John/Isabella/Eleanor");
    
  VRContainer fifthTestList;

  fifthTestList.push_back("/MVR/John/Isabella");
  fifthTestList.push_back("/MVR/John/Isabella/Eleanor");
  fifthTestList.push_back("/MVR/John/Isabella/Henry");
  fifthTestList.push_back("/MVR/John/Isabella/Isabella");
  fifthTestList.push_back("/MVR/John/Isabella/Joan");
  fifthTestList.push_back("/MVR/John/Isabella/Richard");
  
  VRContainer sixthTestList;

  sixthTestList.push_back("/MVR/John/Isabella/Isabella");
  sixthTestList.push_back("/MVR/John/Unknown/Isabella");
    
  
  int out = 0;

  LOOP {
    VRDataIndex *index = new VRDataIndex();
    index->addSerializedValue(xmlteststring, VRDataIndex::rootNameSpace);
    
    // Test selection by attribute, not dependent on value.
    VRContainer firstList = index->selectByAttribute("name", "*");

    VRContainer::iterator jt = firstTestList.begin(); 
    for (VRContainer::iterator it = firstList.begin();
         it != firstList.end(); it++) {

      if (jt == firstTestList.end()) {

        std::cout << "mismatch:" << *it << std::endl;
        return 1;
      }

      // Here's the test.
      if ((*it).compare(*jt++) != 0) out++;
    }

    // Test selection by attribute, specific value
    VRContainer secondList = index->selectByAttribute("name", "FitzRoy");

    jt = secondTestList.begin(); 
    for (VRContainer::iterator it = secondList.begin();
         it != secondList.end(); it++) {

      if (jt == secondTestList.end()) {

        std::cout << "mismatch:" << *it << std::endl;
        return 1;
      }

      if ((*it).compare(*jt++) != 0) out++;
    }

    // Test selection by type.
    VRContainer thirdList = index->selectByType(VRCORETYPE_STRING);
        
    jt = thirdTestList.begin();
    for (VRContainer::iterator it = thirdList.begin();
         it != thirdList.end(); it++) {

      if (jt == thirdTestList.end()) {

        std::cout << "mismatch:" << *it << std::endl;
        return 1;
      }
    
      if ((*it).compare(*jt++) != 0) out++;
    }

  
    // Test selection by fully qualified name.
    VRContainer fourthList = index->selectByName("/MVR/John/Isabella/Eleanor");
        
    jt = fourthTestList.begin();
    for (VRContainer::iterator it = fourthList.begin();
         it != fourthList.end(); it++) {

      if ((*it).compare(*jt++) != 0) out++;
    }

    // Test selection by partial name.
    VRContainer fifthList = index->selectByName("John/Isabella");
        
    jt = fifthTestList.begin();
    for (VRContainer::iterator it = fifthList.begin();
         it != fifthList.end(); it++) {

      if ((*it).compare(*jt++) != 0) out++;
    }


    // Test selection by partial name with wildcard.
    VRContainer sixthList = index->selectByName("John/*/Isabella");
        
    jt = sixthTestList.begin();
    for (VRContainer::iterator it = sixthList.begin();
         it != sixthList.end(); it++) {

      if ((*it).compare(*jt++) != 0) out++;
    }

    delete index;
  }
    
  return out;
}

int testPushPopIndex() {

  int out = 0;

  std::string testString = "<MVR type=\"container\"><Server type=\"container\"><Port type=\"string\">3490</Port><Host type=\"string\">localhost</Host><NumClients type=\"int\">1</NumClients></Server><VRPlugins type=\"container\"><MinVRDefaultPlugins type=\"container\"><Names type=\"stringarray\" separator=\"@\">MinVR_GLFW@MinVR_OpenGL@MinVR_Threading</Names><Data type=\"doublearray\">1.200000,2.300000,3.400000,4.500000,5.600000</Data></MinVRDefaultPlugins></VRPlugins><VRDisplayDevices type=\"container\"><ThreadedDisplay type=\"container\"><displayType type=\"string\">thread_group</displayType><Display1 type=\"container\"><allowThreading type=\"int\">1</allowThreading><displayType type=\"string\" val=\"heavy\">glfw_display</displayType><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">200</width><height type=\"int\">200</height></Display1><Display2 type=\"container\"><displayType type=\"string\">glfw_display</displayType><allowThreading type=\"int\">1</allowThreading><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">250</yOffset><width type=\"int\">200</width><height type=\"int\">200</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType></stereoFormatter></Display2><Display3 type=\"container\"><displayType type=\"string\">glfw_display</displayType><allowThreading type=\"int\">1</allowThreading><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">450</yOffset><width type=\"int\">200</width><height type=\"int\">200</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType></stereoFormatter></Display3></ThreadedDisplay><MainDisplay type=\"container\"><displayType type=\"string\">glfw_display</displayType><xOffset type=\"int\">800</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">300</width><height type=\"int\">600</height></MainDisplay><OtherDisplay type=\"container\"><displayType type=\"string\">glfw_display</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">600</width><height type=\"int\">600</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType><topViewport type=\"container\"><displayType type=\"string\">viewport</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset><width type=\"int\">600</width><height type=\"int\">300</height></topViewport><bottomViewport type=\"container\"><displayType type=\"string\">viewport</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">600</width><height type=\"int\">300</height></bottomViewport></stereoFormatter></OtherDisplay><radius type=\"double\">20.000000</radius><Display1 type=\"container\"><radius type=\"double\">7.000000</radius><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset></Display1><Display2 type=\"container\"><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset></Display2></VRDisplayDevices></MVR>";

  std::string testStringPushed = "<MVR type=\"container\"><Server type=\"container\"><Port type=\"string\">3490</Port><Host type=\"string\">hello there</Host><NumClients type=\"int\">12</NumClients></Server><VRPlugins type=\"container\"><MinVRDefaultPlugins type=\"container\"><Names type=\"stringarray\" separator=\"@\">MinVR_GLFW@MinVR_OpenGL@MinVR_Threading</Names><Data type=\"doublearray\">1.200000,2.300000,3.400000,4.500000,5.600000</Data></MinVRDefaultPlugins></VRPlugins><VRDisplayDevices type=\"container\"><ThreadedDisplay type=\"container\"><displayType type=\"string\">thread_group</displayType><Display1 type=\"container\"><allowThreading type=\"int\">1</allowThreading><displayType type=\"string\" val=\"heavy\">glfw_display</displayType><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">200</width><height type=\"int\">200</height></Display1><Display2 type=\"container\"><displayType type=\"string\">glfw_display</displayType><allowThreading type=\"int\">1</allowThreading><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">250</yOffset><width type=\"int\">200</width><height type=\"int\">200</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType></stereoFormatter></Display2><Display3 type=\"container\"><displayType type=\"string\">glfw_display</displayType><allowThreading type=\"int\">1</allowThreading><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">450</yOffset><width type=\"int\">200</width><height type=\"int\">200</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType></stereoFormatter></Display3></ThreadedDisplay><MainDisplay type=\"container\"><displayType type=\"string\">glfw_display</displayType><xOffset type=\"int\">800</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">300</width><height type=\"int\">600</height></MainDisplay><OtherDisplay type=\"container\"><displayType type=\"string\">glfw_display</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">600</width><height type=\"int\">600</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType><topViewport type=\"container\"><displayType type=\"string\">viewport</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset><width type=\"int\">600</width><height type=\"int\">300</height></topViewport><bottomViewport type=\"container\"><displayType type=\"string\">viewport</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">600</width><height type=\"int\">300</height></bottomViewport></stereoFormatter></OtherDisplay><radius type=\"double\">20.000000</radius><Display1 type=\"container\"><radius type=\"double\">7.000000</radius><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset></Display1><Display2 type=\"container\"><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset></Display2></VRDisplayDevices><george type=\"container\"><a0 type=\"int\">4</a0><a1 type=\"int\">5</a1><a2 type=\"int\">6</a2><a3 type=\"int\">7</a3><a4 type=\"int\">8</a4><a5 type=\"int\">9</a5><a6 type=\"int\">10</a6><a7 type=\"int\">11</a7><a8 type=\"int\">12</a8><a9 type=\"int\">13</a9></george><martha type=\"container\"><b0 type=\"double\">3.141593</b0><b1 type=\"double\">3.141593</b1><b2 type=\"double\">6.283185</b2><b3 type=\"double\">9.424778</b3><b4 type=\"double\">12.566370</b4><b5 type=\"double\">15.707963</b5><b6 type=\"double\">18.849556</b6><b7 type=\"double\">21.991148</b7><b8 type=\"double\">25.132741</b8><b9 type=\"double\">28.274333</b9></martha><john type=\"container\"><c0 type=\"string\">abigail0</c0><c1 type=\"string\">abigail1</c1><c2 type=\"string\">abigail2</c2><c3 type=\"string\">abigail3</c3><c4 type=\"string\">abigail4</c4><c5 type=\"string\">abigail5</c5><c6 type=\"string\">abigail6</c6><c7 type=\"string\">abigail7</c7><c8 type=\"string\">abigail8</c8><c9 type=\"string\">abigail9</c9></john><donna type=\"container\"><d0 type=\"doublearray\">1.200000,2.300000,3.400000,4.500000,5.600000</d0></donna></MVR>";

  std::string testStringSecondPush = "<Server type=\"container\"><Port type=\"string\">3490</Port><Host type=\"string\">localhost</Host><NumClients type=\"int\">1</NumClients><walterjohnson type=\"string\">Big Train</walterjohnson></Server>";
  
  LOOP {
    VRDataIndex *n = setupIndex();

    std::string output = n->serialize("/MVR");

    out += output.compare(testString);
    
    n->pushState();

    VRInt a = 4;
    VRDouble b = 3.1415926;
  
    n->addData("/MVR/george/a0", a);
    n->addData("/MVR/george/a1", a + 1);
    n->addData("/MVR/george/a2", a + 2);
    n->addData("/MVR/george/a3", a + 3);
    n->addData("/MVR/george/a4", a + 4);
    n->addData("a5", "/MVR/george/", a + 5);
    n->addData("a6", "/MVR/george/", a + 6);
    n->addData("a7", "/MVR/george/", a + 7);
    n->addData("a8", "/MVR/george/", a + 8);
    n->addData("a9", "/MVR/george/", a + 9);

    n->addData("/MVR/martha/b0", b);
    n->addData("/MVR/martha/b1", b * 1);
    n->addData("/MVR/martha/b2", b * 2);
    n->addData("/MVR/martha/b3", b * 3);
    n->addData("/MVR/martha/b4", b * 4);
    n->addData("b5", "/MVR/martha/", b * 5);
    n->addData("b6", "/MVR/martha/", b * 6);
    n->addData("b7", "/MVR/martha/", b * 7);
    n->addData("b8", "/MVR/martha", b * 8); // misspelled to check on validation
    n->addData("b9", "/MVR/martha", b * 9);

    VRString c = "abigail";
    n->addData("/MVR/john/c0", c + "0");
    n->addData("/MVR/john/c1", c + "1");
    n->addData("/MVR/john/c2", c + "2");
    n->addData("/MVR/john/c3", c + "3");
    n->addData("/MVR/john/c4", c + "4");
    n->addData("/MVR/john/c5", c + "5");
    n->addData("/MVR/john/c6", c + "6");
    n->addData("/MVR/john/c7", c + "7");
    n->addData("/MVR/john/c8", c + "8");
    n->addData("/MVR/john/c9", c + "9");

    n->pushState();

    n->addData("/MVR/Server/walterjohnson","Big Train");
    output = n->serialize("/MVR/Server");
    out += output.compare(testStringPushed);

    //std::cout << output << std::endl;
    
    n->popState();

    
    std::vector<double>d;
    d.push_back(1.2);
    d.push_back(2.3);
    d.push_back(3.4);
    d.push_back(4.5);
    d.push_back(5.6);

    n->addData("/MVR/donna/d0", d);

    n->addData("/MVR/Server/Host", "hello there");
    n->addData("/MVR/Server/NumClients", 12);
    
    output = n->serialize("/MVR");

    out += output.compare(testStringSecondPush);

    //std::cout << output << std::endl;
    
    n->popState();
 
    output = n->serialize("/MVR");

    out += output.compare(testString);
    delete n;
  }
  return out;
}

int testIndexSerializeIntArray() {

  std::string testString = "<atestarray type=\"intarray\">0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99</atestarray>";

  int out = 0;

  LOOP {
    VRDataIndex *n = setupIndex();

    std::vector<int>e;

    for (int i = 0; i < 100; i++) {
      e.push_back(i);
    }

    n->addData("/george/atestarray", e);
  
    std::string output = n->serialize("atestarray", "/george");
  
    delete n;

    out = output.compare(testString);
  }

  return out;
    
}

int testIndexSerializeIntArraySep() {

  std::string testString = "<atestarray type=\"intarray\" separator=\"@\">0@1@2@3@4@5@6@7@8@9@10@11@12@13@14@15@16@17@18@19@20@21@22@23@24@25@26@27@28@29@30@31@32@33@34@35@36@37@38@39@40@41@42@43@44@45@46@47@48@49@50@51@52@53@54@55@56@57@58@59@60@61@62@63@64@65@66@67@68@69@70@71@72@73@74@75@76@77@78@79@80@81@82@83@84@85@86@87@88@89@90@91@92@93@94@95@96@97@98@99</atestarray>";

  int out = 0;

  LOOP {
    VRDataIndex *n = setupIndex();

    std::vector<int>e;

    for (int i = 0; i < 100; i++) {
      e.push_back(i);
    }

    n->addData("/george/atestarray", e);
    n->getDatum("/george/atestarray")->setAttributeValue("separator", "@");

    std::string output = n->serialize("atestarray", "/george");
  
    delete n;

    out += output.compare(testString);
  }

  return out;    
}

int testIndexSerialize() {

  std::string testString = "<MVR type=\"container\"><Server type=\"container\"><Port type=\"string\">3490</Port><Host type=\"string\">localhost</Host><NumClients type=\"int\">1</NumClients></Server><VRPlugins type=\"container\"><MinVRDefaultPlugins type=\"container\"><Names type=\"stringarray\" separator=\"@\">MinVR_GLFW@MinVR_OpenGL@MinVR_Threading</Names><Data type=\"doublearray\">1.200000,2.300000,3.400000,4.500000,5.600000</Data></MinVRDefaultPlugins></VRPlugins><VRDisplayDevices type=\"container\"><ThreadedDisplay type=\"container\"><displayType type=\"string\">thread_group</displayType><Display1 type=\"container\"><allowThreading type=\"int\">1</allowThreading><displayType type=\"string\" val=\"heavy\">glfw_display</displayType><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">200</width><height type=\"int\">200</height></Display1><Display2 type=\"container\"><displayType type=\"string\">glfw_display</displayType><allowThreading type=\"int\">1</allowThreading><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">250</yOffset><width type=\"int\">200</width><height type=\"int\">200</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType></stereoFormatter></Display2><Display3 type=\"container\"><displayType type=\"string\">glfw_display</displayType><allowThreading type=\"int\">1</allowThreading><xOffset type=\"int\">600</xOffset><yOffset type=\"int\">450</yOffset><width type=\"int\">200</width><height type=\"int\">200</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType></stereoFormatter></Display3></ThreadedDisplay><MainDisplay type=\"container\"><displayType type=\"string\">glfw_display</displayType><xOffset type=\"int\">800</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">300</width><height type=\"int\">600</height></MainDisplay><OtherDisplay type=\"container\"><displayType type=\"string\">glfw_display</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">600</width><height type=\"int\">600</height><stereoFormatter type=\"container\"><displayType type=\"string\">sideBySideStereo</displayType><topViewport type=\"container\"><displayType type=\"string\">viewport</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset><width type=\"int\">600</width><height type=\"int\">300</height></topViewport><bottomViewport type=\"container\"><displayType type=\"string\">viewport</displayType><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">0</yOffset><width type=\"int\">600</width><height type=\"int\">300</height></bottomViewport></stereoFormatter></OtherDisplay><radius type=\"double\">20.000000</radius><Display1 type=\"container\"><radius type=\"double\">7.000000</radius><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset></Display1><Display2 type=\"container\"><xOffset type=\"int\">0</xOffset><yOffset type=\"int\">300</yOffset></Display2></VRDisplayDevices></MVR>";

  int out = 0;

  LOOP {
  
    VRDataIndex *n = setupIndex();

    std::string output = n->serialize("/MVR");

    delete n;

    out += output.compare(testString);
  }

  return out;
  
}

int testIndexPrintDoubleArray() {

  std::string testString = " | donna\n |  | d0 = 1.200000,2.300000,3.400000,4.500000,5.600000 (doublearray)\n";

  int out = 0;

  LOOP {
  
    VRDataIndex *n = setupIndex();

    std::string output = n->printStructure("/donna",200);  
    delete n;

    //    std::cout << "output:     " << output << std::endl;
    //    std::cout << "testString: " << testString << std::endl;

    out += output.compare(testString);
  }

  return out;  
}
  
int testIndexLotsaEntries() {

  int out = 0;

  LOOP {
  
    VRDataIndex *n = setupIndex();

    int lctr;
    int N = 1000;
  
    for (lctr = 0; lctr < N; lctr++) {
      std::stringstream name;
      name << "/henry/entry" << lctr;

      n->addData(name.str(), lctr);   
    }

    for (lctr = 0; lctr < N; lctr++) {
      std::stringstream name;
      name << "/henry/entry" << lctr;

      out += ((lctr == (int)n->getValue(name.str())) ? 0 : 1);
    }

    delete n;
  }

  return out;
}
  
int testEscapedChars() {

  int out = 0;

  int lctr;
  int N = 1000;

  LOOP {

    VRDataIndex *n = setupIndex();

    // Escaping the comma separator between Gamma and Delta.
    std::string inString = "<mimi type=\"stringarray\" separator=\",\">Alpha,Beta,Gamma\\,Delta,Epsilon</mimi>";
    n->addSerializedValue(inString, VRDataIndex::rootNameSpace);
    
    VRStringArray s = n->getValue("/mimi");

    out += (s.size() == 4) ? 0 : 1;

    out += s[0].compare("Alpha");
    out += s[1].compare("Beta");
    out += s[2].compare("Gamma,Delta");
    out += s[3].compare("Epsilon");

    //    std::cout << inString << std::endl;
    //    std::cout << s[0] << "/"  << s[1] << "/"  << s[2] << "/"  << s[3] << "/" << std::endl;
    delete n;
  }

  return out;
}

// Test the linking of one node to another with the linkNode
// attribute.  There are three linkNodes in the xmlstring, one with an
// absolute link name, and the other two using the same name, but
// differing in the context in which the name is interpreted.
int testLinkNode() {
  std::string xmlstring =  "<MVR><!-- some of the illegitimate children of John I --><John name=\"Lackland\"><Isabella name=\"Angouleme\"><Henry seq=\"III\" title=\"King\">1</Henry> <Izzie linkNode=\"Isabella\"/><Richard title=\"Earl of Cornwall\">2</Richard> <Joan title=\"Queen Consort\">3</Joan> <Isabella title=\"Queen Consort\">4</Isabella> <Eleanor type=\"string\">5</Eleanor> </Isabella><Joan title=\"Lady of Wales\"><Richard name=\"FitzRoy\">6</Richard><Izzie linkNode=\"Isabella\"/><Oliver name=\"FitzRoy\">7</Oliver></Joan> <Unknown><Geoffrey name=\"FitzRoy\" type=\"string\">8</Geoffrey><John name=\"FitzRoy\">9</John> <Henry name=\"FitzRoy\">10</Henry> <Osbert name=\"Gifford\">11</Osbert><Thomas linkNode=\"/MVR/John/Joan\"/> <Eudes name=\"FitzRoy\">12</Eudes> <Bartholomew name=\"FitzRoy\">13</Bartholomew> <Maud name=\"FitzRoy\" title=\"Abbess of Barking\">14</Maud><Isabella name=\"FitzRoy\">15</Isabella><Philip name=\"FitzRoy\" type=\"string\">16</Philip></Unknown> </John></MVR>";
  
  std::string teststring="<MVR type=\"container\"><John type=\"container\" name=\"Lackland\"><Isabella type=\"container\" name=\"Angouleme\"><Henry type=\"int\" seq=\"III\" title=\"King\">1</Henry><Izzie type=\"int\" title=\"Queen Consort\">4</Izzie><Richard type=\"int\" title=\"Earl of Cornwall\">2</Richard><Joan type=\"int\" title=\"Queen Consort\">3</Joan><Isabella type=\"int\" title=\"Queen Consort\">4</Isabella><Eleanor type=\"string\">5</Eleanor></Isabella><Joan type=\"container\" letter=\"alpha\" title=\"Lady of Wales\"><Richard type=\"int\" name=\"FitzRoy\">6</Richard><Izzie type=\"container\" name=\"Angouleme\"><Henry type=\"int\" seq=\"III\" title=\"King\">1</Henry><Izzie type=\"int\" title=\"Queen Consort\">4</Izzie><Richard type=\"int\" title=\"Earl of Cornwall\">2</Richard><Joan type=\"int\" title=\"Queen Consort\">3</Joan><Isabella type=\"int\" title=\"Queen Consort\">4</Isabella><Eleanor type=\"string\">5</Eleanor></Izzie><Oliver type=\"int\" name=\"FitzRoy\">7</Oliver></Joan><Unknown type=\"container\"><Geoffrey type=\"string\" name=\"FitzRoy\">8</Geoffrey><John type=\"int\" name=\"FitzRoy\">9</John><Henry type=\"int\" name=\"FitzRoy\">10</Henry><Osbert type=\"int\" name=\"Gifford\">11</Osbert><Thomas type=\"container\" letter=\"alpha\" title=\"Lady of Wales\"><Richard type=\"int\" name=\"FitzRoy\">6</Richard><Izzie type=\"container\" name=\"Angouleme\"><Henry type=\"int\" seq=\"III\" title=\"King\">1</Henry><Izzie type=\"int\" title=\"Queen Consort\">4</Izzie><Richard type=\"int\" title=\"Earl of Cornwall\">2</Richard><Joan type=\"int\" title=\"Queen Consort\">3</Joan><Isabella type=\"int\" title=\"Queen Consort\">4</Isabella><Eleanor type=\"string\">5</Eleanor></Izzie><Oliver type=\"int\" name=\"FitzRoy\">7</Oliver></Thomas><Eudes type=\"int\" name=\"FitzRoy\">12</Eudes><Bartholomew type=\"int\" name=\"FitzRoy\">13</Bartholomew><Maud type=\"int\" name=\"FitzRoy\" title=\"Abbess of Barking\">14</Maud><Isabella type=\"int\" name=\"FitzRoy\">15</Isabella><Philip type=\"string\" name=\"FitzRoy\">16</Philip></Unknown></John></MVR>";
  int out = 0;

  LOOP {
    VRDataIndex *index = new VRDataIndex();
    index->addSerializedValue(xmlstring, VRDataIndex::rootNameSpace, false);

    std::cout << index->printStructure() << std::endl;

    // Look for all the nodes with 'linkNode' attributes, and evaluate.
    index->linkNodes();

    // To prove that the linked nodes are actually the same node.  We
    // adjust one node's attributes to make sure it appears at the copy,
    // as well.
    index->getDatum("/MVR/John/Unknown/Thomas")->setAttributeValue("letter", "alpha");

    std::cout << index->printStructure() << std::endl;
  
    std::string outputstring = index->serialize("/MVR");

    out += teststring.compare(outputstring);
    delete index;
  }
  return out;

}

int testLinkContent() {

  std::string xmlstring =  "<MVR><!-- some of the illegitimate children of John I --><John name=\"Lackland\"><Isabella name=\"Angouleme\"><Henry seq=\"III\" title=\"King\">1</Henry> <Richard title=\"Earl of Cornwall\">2</Richard> <Joan title=\"Queen Consort\">3</Joan> <Isabella title=\"Queen Consort\">4</Isabella> <Eleanor type=\"string\">5</Eleanor> </Isabella><Joan title=\"Lady of Wales\"><Richard name=\"FitzRoy\">6</Richard><Oliver name=\"FitzRoy\">7</Oliver></Joan> <Unknown><Geoffrey name=\"FitzRoy\" type=\"string\">8</Geoffrey><John name=\"FitzRoy\">9</John> <Henry name=\"FitzRoy\">10</Henry> <Osbert name=\"Gifford\">11</Osbert><Thomas linkContent=\"/MVR/John/Joan\"/> <Eudes name=\"FitzRoy\">12</Eudes> <Bartholomew name=\"FitzRoy\">13</Bartholomew> <Maud name=\"FitzRoy\" title=\"Abbess of Barking\">14</Maud><Isabella name=\"FitzRoy\">15</Isabella><Philip name=\"FitzRoy\" type=\"string\">16</Philip></Unknown> </John></MVR>";

 std:;string teststring = "<MVR type=\"container\"><John type=\"container\" name=\"Lackland\"><Isabella type=\"container\" name=\"Angouleme\"><Henry type=\"int\" seq=\"III\" title=\"King\">1</Henry><Richard type=\"int\" title=\"Earl of Cornwall\">2</Richard><Joan type=\"int\" title=\"Queen Consort\">3</Joan><Isabella type=\"int\" title=\"Queen Consort\">4</Isabella><Eleanor type=\"string\">5</Eleanor></Isabella><Joan type=\"container\" title=\"Lady of Wales\"><Richard type=\"int\" name=\"FitzRoy\">6</Richard><Oliver type=\"int\" name=\"FitzRoy\">7</Oliver></Joan><Unknown type=\"container\"><Richard type=\"int\" name=\"FitzRoy\">6</Richard><Oliver type=\"int\" name=\"FitzRoy\">7</Oliver><Geoffrey type=\"string\" name=\"FitzRoy\">8</Geoffrey><John type=\"int\" name=\"FitzRoy\">9</John><Henry type=\"int\" name=\"FitzRoy\">10</Henry><Osbert type=\"int\" name=\"Gifford\">11</Osbert><Eudes type=\"int\" name=\"FitzRoy\">12</Eudes><Bartholomew type=\"int\" name=\"FitzRoy\">13</Bartholomew><Maud type=\"int\" name=\"FitzRoy\" title=\"Abbess of Barking\">14</Maud><Isabella type=\"int\" name=\"FitzRoy\">15</Isabella><Philip type=\"string\" name=\"FitzRoy\">16</Philip></Unknown></John></MVR>";

  
  int out = 0;
  LOOP {
    VRDataIndex *index = new VRDataIndex();
    index->addSerializedValue(xmlstring, VRDataIndex::rootNameSpace, false);

    //  std::cout << index->printStructure() << std::endl;

    // Look for all the nodes with 'linknode' attributes, and evaluate.
    index->linkNodes(); index->linkContent();

    // To prove that the copied nodes are actually the same node.  We
    // adjust one node's attributes to make sure it appears at the copy,
    // as well.
    //  index->getDatum("/MVR/John/Unknown/Thomas")->setAttributeValue("letter", "alpha");

    out +=  teststring.compare(index->serialize("/MVR"));
    delete index;
  }

  return out;

}
