// Copyright 2015 Google Inc. All rights reserved
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RULE_H_
#define RULE_H_

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "eval.h"
#include "loc.h"
#include "log.h"
#include "stmt.h"
#include "string_piece.h"
#include "strutil.h"
#include "symtab.h"

using namespace std;

class Value;

class Rule {
 public:
  Rule();

  Loc cmd_loc() const { return Loc(loc.filename, cmd_lineno); }

  string DebugString() const;

  void ParsePrerequisites(const StringPiece& line,
                          size_t pos,
                          const RuleStmt* rule_stmt);

  static bool IsPatternRule(const StringPiece& target_string) {
    return target_string.find('%') != string::npos;
  }

  void ParseInputs(Evaluator* ev);
  shared_ptr<Rule> ApplyPattern(Pattern pat, Symbol output) const;

  vector<Symbol> outputs;
  vector<Symbol> inputs;
  vector<Symbol> order_only_inputs;
  vector<Symbol> output_patterns;
  vector<Symbol> validations;
  bool is_double_colon;
  bool is_suffix_rule;
  bool second_expansion;
  bool parsed_inputs;
  vector<Value*> cmds;
  Loc loc;
  int cmd_lineno;
  string prereq_string;

 private:
  void Error(const string& msg) { ERROR_LOC(loc, "%s", msg.c_str()); }
  void ParseInputs(const StringPiece& inputs_string);
};

#endif  // RULE_H_
