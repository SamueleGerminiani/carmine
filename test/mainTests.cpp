/**
 * @copyright Copyright © 2018 CNF_Simplifier. All rights reserved.
 *
 * @license{<blockquote>
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * </blockquote>}
 *
 * @author Samuele Germiniani <br> Univerity of Verona, Dept. of Computer
 * Science                   <br> samuele.germiniani@univr.it
 * @date 2020
 * @version v1.0
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "stdlib.h"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

#include "antlr4-runtime.h"
#include "propositionLexer.h"
#include "propositionParser.h"
#include "testCaseGenerator.hh"

#include "oden/classes/classes.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/propositionUtils.hh"
#include "oden/odenUtils/xmlUtils.hh"

#include "Hierarchical.hh"
#include "parserUtils.hh"
#include "testCaseGenerator.hh"
#include "z3/z3TestCaseGenerator.h"

namespace oden {

void printAllKLengthRec(std::vector<std::vector<int>> &solutions,
                        std::vector<int> prefix, int n, int k) {
  // Base case: k is 0,
  // print prefix
  if (k == 0) {
    solutions.push_back(prefix);
    return;
  }

  // One by one add all characters
  // from set and recursively
  // call for k equals to k-1
  for (int i = 0; i < n; i++) {
    std::vector<int> newPrefix;

    // Next character of input added
    newPrefix = prefix;
    newPrefix.push_back(i);

    // k is decreased, because
    // we have added a new character
    printAllKLengthRec(solutions, newPrefix, n, k - 1);
  }
}
void checkShape(const std::vector<std::string> &cTypes, std::string &formula,
                size_t nVars, size_t nTestCases) {

  std::vector<std::string> allTestInstances;

  // Generate all combinations of types of size 'nVars'
  std::cout << "Generating combinations of types...";
  std::vector<std::vector<int>> solutions;
  std::vector<int> initialPrefix;
  printAllKLengthRec(solutions, initialPrefix, cTypes.size(), nVars);
  std::string varDeclaration = "";

  // convert each type combination to a variables declaration
  for (auto prefix : solutions) {
    for (size_t i = 0; i < prefix.size(); i++) {
      varDeclaration =
          varDeclaration + cTypes[prefix[i]] + " p" + std::to_string(i) + ";";
    }
    allTestInstances.push_back(varDeclaration);
    varDeclaration = "";
    // std::cout <<varDeclaration <<"\n";
  }
  std::cout << "Done!\n";

  // Generate a test for each type
  std::string fileName = "sampleMain.cpp";
  std::string fileBegin = "#include<cassert>\nint main(){\n";
  std::string fileEnd = "return 0;\n}";

  for (auto &testInstance : allTestInstances) {
    std::string shape = formula;
    std::cout << testInstance << "\n";
    Proposition *p = oden::parseProposition(shape, testInstance);

    // For each type
    std::cout << shape << "\n";

    messageInfo("PROPOSITION: " + oden::prop2String(*p));

    // Generate N testcases for the given type + shape
    z3::Z3TestCaseGenerator gen;
    auto testCases = gen.generateTestCase(*p, nTestCases);
    // REQUIRE(!testCases.empty());

    // Open the current cpp test file.
    std::ofstream myfile;
    myfile.open(fileName);
    assert(myfile.is_open());
    myfile << fileBegin;
    // add var declaration
    myfile << testInstance << "\n";

    for (const z3::TestCase &tc : testCases) {
      for (const z3::Assignment &ass : tc) {
        // init vars with values generated with z3
        switch (ass.second.first) {
        case VarType::Bool:
          myfile << ass.first << "=" << std::to_string(ass.second.second.bVal)
                 << ";\n";
          break;
        case VarType::Numeric:
          myfile << ass.first << "=" << std::fixed << std::setprecision(400)
                 << ass.second.second.dVal << ";\n";
          break;
        case VarType::SLogic:
          myfile << ass.first << "=" << std::to_string(ass.second.second.sVal)
                 << ";\n";
          break;
        case VarType::ULogic:
          myfile << ass.first << "=" << std::to_string(ass.second.second.uVal)
                 << ";\n";
          break;
        } // for all assignments of variables in the current testcase
      }
      // add an assertion to check to evaluate the formula
      myfile << "assert(" << formula << ");"
             << "\n";
    } // for all the current testcases
    myfile << fileEnd;
    myfile.close();

    // compile cpp the test file
    system(("gcc -w " + fileName + " -o testbin.x").c_str());
    // execute the file to check if the assertions are all true
    // if an assertion fails the executable will return -1.
    REQUIRE(system("./testbin.x") == 0);

    delete p;

  } // for all instances
}
TEST_CASE("Shape1 test", "[Shape1]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("char");
  cTypes.push_back("short");
  cTypes.push_back("int");
  cTypes.push_back("long long");
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");
  /*
  cTypes.push_back("float");
  cTypes.push_back("double");
  */
  // Generate test-cases for given formula + types

  std::string formula = "p0 + p1 < p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}

TEST_CASE("Shape2 test", "[Shape2]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("char");
  cTypes.push_back("short");
  cTypes.push_back("int");
  cTypes.push_back("long long");
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");
  /*
  cTypes.push_back("float");
  cTypes.push_back("double");
  */

  // Generate test-cases for given formula + types

  std::string formula = "p0 + p1 == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}

TEST_CASE("Shape3 test", "[Shape3]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("char");
  cTypes.push_back("short");
  cTypes.push_back("int");
  cTypes.push_back("long long");
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");
  /*
  cTypes.push_back("float");
  cTypes.push_back("double");
  */

  // Generate test-cases for given formula + types

  std::string formula = "p0 - p1 > p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}

TEST_CASE("Shape4 test", "[Shape4]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("char");
  cTypes.push_back("short");
  cTypes.push_back("int");
  cTypes.push_back("long long");
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");
  /*
  cTypes.push_back("float");
  cTypes.push_back("double");
  */

  // Generate test-cases for given formula + types

  std::string formula = "p0 * p1 > p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape5 test", "[Shape5]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("char");
  cTypes.push_back("short");
  cTypes.push_back("int");
  cTypes.push_back("long long");
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");
  /*
  cTypes.push_back("float");
  cTypes.push_back("double");
  */

  // Generate test-cases for given formula + types

  std::string formula = "p0 / p1 == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape6 test", "[Shape6]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");

  // Generate test-cases for given formula + types

  std::string formula = "(p0 | p1) == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape7 test", "[Shape7]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");

  // Generate test-cases for given formula + types

  std::string formula = "(p0 & p1) == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape8 test", "[Shape8]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("unsigned char");
  cTypes.push_back("unsigned short");
  cTypes.push_back("unsigned int");
  cTypes.push_back("unsigned long long");

  // Generate test-cases for given formula + types

  std::string formula = "(p0 ^ p1) == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}

TEST_CASE("Shape9 test", "[Shape9]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("float");
  cTypes.push_back("double");

  // Generate test-cases for given formula + types

  std::string formula = "p0 / p1 < p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape10 test", "[Shape10]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("float");
  cTypes.push_back("double");

  // Generate test-cases for given formula + types

  std::string formula = "p0 / p1 > p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape11 test", "[Shape11]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("float");
  cTypes.push_back("double");

  // Generate test-cases for given formula + types

  std::string formula = "p0 / p1 == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape12 test", "[Shape12]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("float");
  cTypes.push_back("double");

  // Generate test-cases for given formula + types

  std::string formula = "p0 + p1 == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape13 test", "[Shape13]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("float");
  cTypes.push_back("double");

  // Generate test-cases for given formula + types

  std::string formula = "p0 * p1 < p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}
TEST_CASE("Shape14 test", "[Shape14]") {
  std::vector<std::string> cTypes;

  // All available types
  cTypes.push_back("float");
  cTypes.push_back("double");

  // Generate test-cases for given formula + types

  std::string formula = "p0 - p1 == p2";
  const size_t nVars = 3;
  const size_t nTestCases = 5;

  checkShape(cTypes, formula, nVars, nTestCases);
}


} // namespace oden
namespace clustering {
float similarity(const std::vector<int> &e1, const std::vector<int> &e2) {
  float s1 = std::accumulate(begin(e1), end(e1), 0) / (float)e1.size();
  float s2 = std::accumulate(begin(e2), end(e2), 0) / (float)e2.size();
  return s1 < s2 ? s1 / s2 : s2 / s1;
}
TEST_CASE("Hierarchical clustering", "[HC]") {

  std::vector<int> objs;
  std::ifstream myfile;
  myfile.open ("../test/ci.txt");
      while(myfile.good()){
          int tmp;
          myfile>>tmp;
          objs.push_back(tmp);

      }
      std::cout << "Starting clustering..." << "\n";
  Hierarchical<int> cls(objs, &similarity, 0.1f);
  //    std::cout << cls;
  auto bestLevel = cls.getTopLevel();

  std::cout << "Level "
            << "=======================\n";
  size_t clusterID = 0;
  for (const auto &cluster : bestLevel) {
    std::cout << "Cluster " << clusterID << "-----------------------\n";
    for (const auto &obj : cluster) {
      std::cout << obj << " ";
    }
    clusterID++;
    std::cout << "\n";
  }
}
} // namespace codeGenerator

