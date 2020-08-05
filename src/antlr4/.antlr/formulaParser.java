// Generated from /home/moreno/Scrivania/IDEA/grammar/formula.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class formulaParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, LGPAREN=5, RGPAREN=6, LCPAREN=7, RCPAREN=8, 
		LPAREN=9, RPAREN=10, VARIABLE=11, NUMERIC=12, BINARY=13, BOOLEAN=14, STRING=15, 
		PLUS=16, MINUS=17, TIMES=18, DIV=19, GT=20, GE=21, LT=22, LE=23, EQ=24, 
		NEQ=25, BAND=26, BOR=27, BXOR=28, NEG=29, AND=30, OR=31, NOT=32, WS=33;
	public static final int
		RULE_file = 0, RULE_boolean = 1, RULE_booleanAtom = 2, RULE_booleanConstant = 3, 
		RULE_booleanVariable = 4, RULE_logic = 5, RULE_logicAtom = 6, RULE_logicConstant = 7, 
		RULE_logicVariable = 8, RULE_numeric = 9, RULE_numericAtom = 10, RULE_numericConstant = 11, 
		RULE_numericVariable = 12, RULE_string = 13, RULE_stringAtom = 14, RULE_stringConstant = 15, 
		RULE_stringVariable = 16, RULE_constant = 17, RULE_variable = 18, RULE_upper_bound = 19, 
		RULE_lower_bound = 20, RULE_relop = 21;
	public static final String[] ruleNames = {
		"file", "boolean", "booleanAtom", "booleanConstant", "booleanVariable", 
		"logic", "logicAtom", "logicConstant", "logicVariable", "numeric", "numericAtom", 
		"numericConstant", "numericVariable", "string", "stringAtom", "stringConstant", 
		"stringVariable", "constant", "variable", "upper_bound", "lower_bound", 
		"relop"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "',bool>'", "',logic>'", "',numeric>'", "',string>'", "'{'", "'}'", 
		"'['", "']'", "'('", "')'", null, null, null, null, null, "'+'", "'-'", 
		"'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&'", "'|'", 
		"'^'", "'~'", "'&&'", "'||'", "'!'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, "LGPAREN", "RGPAREN", "LCPAREN", "RCPAREN", 
		"LPAREN", "RPAREN", "VARIABLE", "NUMERIC", "BINARY", "BOOLEAN", "STRING", 
		"PLUS", "MINUS", "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", 
		"BAND", "BOR", "BXOR", "NEG", "AND", "OR", "NOT", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "formula.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public formulaParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class FileContext extends ParserRuleContext {
		public BooleanContext boolean() {
			return getRuleContext(BooleanContext.class,0);
		}
		public TerminalNode EOF() { return getToken(formulaParser.EOF, 0); }
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			boolean(0);
			setState(45);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BooleanContext extends ParserRuleContext {
		public Token booleanop;
		public TerminalNode LPAREN() { return getToken(formulaParser.LPAREN, 0); }
		public List<BooleanContext> boolean() {
			return getRuleContexts(BooleanContext.class);
		}
		public BooleanContext boolean(int i) {
			return getRuleContext(BooleanContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(formulaParser.RPAREN, 0); }
		public TerminalNode LCPAREN() { return getToken(formulaParser.LCPAREN, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public TerminalNode RCPAREN() { return getToken(formulaParser.RCPAREN, 0); }
		public TerminalNode NOT() { return getToken(formulaParser.NOT, 0); }
		public List<LogicContext> logic() {
			return getRuleContexts(LogicContext.class);
		}
		public LogicContext logic(int i) {
			return getRuleContext(LogicContext.class,i);
		}
		public RelopContext relop() {
			return getRuleContext(RelopContext.class,0);
		}
		public List<NumericContext> numeric() {
			return getRuleContexts(NumericContext.class);
		}
		public NumericContext numeric(int i) {
			return getRuleContext(NumericContext.class,i);
		}
		public TerminalNode EQ() { return getToken(formulaParser.EQ, 0); }
		public List<StringContext> string() {
			return getRuleContexts(StringContext.class);
		}
		public StringContext string(int i) {
			return getRuleContext(StringContext.class,i);
		}
		public TerminalNode NEQ() { return getToken(formulaParser.NEQ, 0); }
		public BooleanAtomContext booleanAtom() {
			return getRuleContext(BooleanAtomContext.class,0);
		}
		public TerminalNode AND() { return getToken(formulaParser.AND, 0); }
		public TerminalNode OR() { return getToken(formulaParser.OR, 0); }
		public BooleanContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolean; }
	}

	public final BooleanContext boolean() throws RecognitionException {
		return boolean(0);
	}

	private BooleanContext boolean(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		BooleanContext _localctx = new BooleanContext(_ctx, _parentState);
		BooleanContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_boolean, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				{
				setState(48);
				match(LPAREN);
				setState(49);
				boolean(0);
				setState(50);
				match(RPAREN);
				}
				break;
			case 2:
				{
				setState(52);
				match(LCPAREN);
				setState(53);
				constant();
				setState(54);
				match(RCPAREN);
				setState(55);
				boolean(16);
				}
				break;
			case 3:
				{
				setState(57);
				match(NOT);
				setState(58);
				boolean(15);
				}
				break;
			case 4:
				{
				setState(59);
				logic(0);
				setState(60);
				relop();
				setState(61);
				logic(0);
				}
				break;
			case 5:
				{
				setState(63);
				numeric(0);
				setState(64);
				relop();
				setState(65);
				numeric(0);
				}
				break;
			case 6:
				{
				setState(67);
				logic(0);
				setState(68);
				match(EQ);
				setState(69);
				logic(0);
				}
				break;
			case 7:
				{
				setState(71);
				numeric(0);
				setState(72);
				match(EQ);
				setState(73);
				numeric(0);
				}
				break;
			case 8:
				{
				setState(75);
				string();
				setState(76);
				match(EQ);
				setState(77);
				string();
				}
				break;
			case 9:
				{
				setState(79);
				logic(0);
				setState(80);
				match(NEQ);
				setState(81);
				logic(0);
				}
				break;
			case 10:
				{
				setState(83);
				numeric(0);
				setState(84);
				match(NEQ);
				setState(85);
				numeric(0);
				}
				break;
			case 11:
				{
				setState(87);
				string();
				setState(88);
				match(NEQ);
				setState(89);
				string();
				}
				break;
			case 12:
				{
				setState(91);
				booleanAtom();
				}
				break;
			case 13:
				{
				setState(92);
				logic(0);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(109);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(107);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(95);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(96);
						match(EQ);
						setState(97);
						boolean(13);
						}
						break;
					case 2:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(98);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(99);
						match(NEQ);
						setState(100);
						boolean(9);
						}
						break;
					case 3:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(101);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(102);
						((BooleanContext)_localctx).booleanop = match(AND);
						setState(103);
						boolean(5);
						}
						break;
					case 4:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(104);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(105);
						((BooleanContext)_localctx).booleanop = match(OR);
						setState(106);
						boolean(4);
						}
						break;
					}
					} 
				}
				setState(111);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class BooleanAtomContext extends ParserRuleContext {
		public BooleanConstantContext booleanConstant() {
			return getRuleContext(BooleanConstantContext.class,0);
		}
		public BooleanVariableContext booleanVariable() {
			return getRuleContext(BooleanVariableContext.class,0);
		}
		public BooleanAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanAtom; }
	}

	public final BooleanAtomContext booleanAtom() throws RecognitionException {
		BooleanAtomContext _localctx = new BooleanAtomContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_booleanAtom);
		try {
			setState(114);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOLEAN:
				enterOuterAlt(_localctx, 1);
				{
				setState(112);
				booleanConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(113);
				booleanVariable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BooleanConstantContext extends ParserRuleContext {
		public TerminalNode BOOLEAN() { return getToken(formulaParser.BOOLEAN, 0); }
		public BooleanConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanConstant; }
	}

	public final BooleanConstantContext booleanConstant() throws RecognitionException {
		BooleanConstantContext _localctx = new BooleanConstantContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_booleanConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(116);
			match(BOOLEAN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BooleanVariableContext extends ParserRuleContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public BooleanVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanVariable; }
	}

	public final BooleanVariableContext booleanVariable() throws RecognitionException {
		BooleanVariableContext _localctx = new BooleanVariableContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_booleanVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(118);
			match(LT);
			setState(119);
			variable();
			setState(120);
			match(T__0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LogicContext extends ParserRuleContext {
		public Token artop;
		public Token logop;
		public TerminalNode LPAREN() { return getToken(formulaParser.LPAREN, 0); }
		public List<LogicContext> logic() {
			return getRuleContexts(LogicContext.class);
		}
		public LogicContext logic(int i) {
			return getRuleContext(LogicContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(formulaParser.RPAREN, 0); }
		public TerminalNode LCPAREN() { return getToken(formulaParser.LCPAREN, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public TerminalNode RCPAREN() { return getToken(formulaParser.RCPAREN, 0); }
		public TerminalNode NEG() { return getToken(formulaParser.NEG, 0); }
		public LogicAtomContext logicAtom() {
			return getRuleContext(LogicAtomContext.class,0);
		}
		public NumericContext numeric() {
			return getRuleContext(NumericContext.class,0);
		}
		public TerminalNode TIMES() { return getToken(formulaParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(formulaParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(formulaParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(formulaParser.MINUS, 0); }
		public TerminalNode BAND() { return getToken(formulaParser.BAND, 0); }
		public TerminalNode BOR() { return getToken(formulaParser.BOR, 0); }
		public LogicContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic; }
	}

	public final LogicContext logic() throws RecognitionException {
		return logic(0);
	}

	private LogicContext logic(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LogicContext _localctx = new LogicContext(_ctx, _parentState);
		LogicContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_logic, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(136);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(123);
				match(LPAREN);
				setState(124);
				logic(0);
				setState(125);
				match(RPAREN);
				}
				break;
			case 2:
				{
				setState(127);
				match(LCPAREN);
				setState(128);
				constant();
				setState(129);
				match(RCPAREN);
				setState(130);
				logic(8);
				}
				break;
			case 3:
				{
				setState(132);
				match(NEG);
				setState(133);
				logic(7);
				}
				break;
			case 4:
				{
				setState(134);
				logicAtom();
				}
				break;
			case 5:
				{
				setState(135);
				numeric(0);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(152);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(150);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(138);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(139);
						((LogicContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==TIMES || _la==DIV) ) {
							((LogicContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(140);
						logic(7);
						}
						break;
					case 2:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(141);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(142);
						((LogicContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
							((LogicContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(143);
						logic(6);
						}
						break;
					case 3:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(144);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(145);
						((LogicContext)_localctx).logop = match(BAND);
						setState(146);
						logic(5);
						}
						break;
					case 4:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(147);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(148);
						((LogicContext)_localctx).logop = match(BOR);
						setState(149);
						logic(4);
						}
						break;
					}
					} 
				}
				setState(154);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class LogicAtomContext extends ParserRuleContext {
		public LogicConstantContext logicConstant() {
			return getRuleContext(LogicConstantContext.class,0);
		}
		public LogicVariableContext logicVariable() {
			return getRuleContext(LogicVariableContext.class,0);
		}
		public LogicAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicAtom; }
	}

	public final LogicAtomContext logicAtom() throws RecognitionException {
		LogicAtomContext _localctx = new LogicAtomContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_logicAtom);
		try {
			setState(157);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BINARY:
				enterOuterAlt(_localctx, 1);
				{
				setState(155);
				logicConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(156);
				logicVariable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LogicConstantContext extends ParserRuleContext {
		public TerminalNode BINARY() { return getToken(formulaParser.BINARY, 0); }
		public LogicConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicConstant; }
	}

	public final LogicConstantContext logicConstant() throws RecognitionException {
		LogicConstantContext _localctx = new LogicConstantContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_logicConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(159);
			match(BINARY);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LogicVariableContext extends ParserRuleContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public LogicVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicVariable; }
	}

	public final LogicVariableContext logicVariable() throws RecognitionException {
		LogicVariableContext _localctx = new LogicVariableContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_logicVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(161);
			match(LT);
			setState(162);
			variable();
			setState(163);
			match(T__1);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NumericContext extends ParserRuleContext {
		public Token artop;
		public TerminalNode LPAREN() { return getToken(formulaParser.LPAREN, 0); }
		public List<NumericContext> numeric() {
			return getRuleContexts(NumericContext.class);
		}
		public NumericContext numeric(int i) {
			return getRuleContext(NumericContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(formulaParser.RPAREN, 0); }
		public TerminalNode LCPAREN() { return getToken(formulaParser.LCPAREN, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public TerminalNode RCPAREN() { return getToken(formulaParser.RCPAREN, 0); }
		public NumericAtomContext numericAtom() {
			return getRuleContext(NumericAtomContext.class,0);
		}
		public TerminalNode TIMES() { return getToken(formulaParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(formulaParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(formulaParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(formulaParser.MINUS, 0); }
		public NumericContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numeric; }
	}

	public final NumericContext numeric() throws RecognitionException {
		return numeric(0);
	}

	private NumericContext numeric(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		NumericContext _localctx = new NumericContext(_ctx, _parentState);
		NumericContext _prevctx = _localctx;
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_numeric, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
				{
				setState(166);
				match(LPAREN);
				setState(167);
				numeric(0);
				setState(168);
				match(RPAREN);
				}
				break;
			case LCPAREN:
				{
				setState(170);
				match(LCPAREN);
				setState(171);
				constant();
				setState(172);
				match(RCPAREN);
				setState(173);
				numeric(4);
				}
				break;
			case NUMERIC:
			case LT:
				{
				setState(175);
				numericAtom();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(186);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(184);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
					case 1:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(178);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(179);
						((NumericContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==TIMES || _la==DIV) ) {
							((NumericContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(180);
						numeric(4);
						}
						break;
					case 2:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(181);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(182);
						((NumericContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
							((NumericContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(183);
						numeric(3);
						}
						break;
					}
					} 
				}
				setState(188);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class NumericAtomContext extends ParserRuleContext {
		public NumericConstantContext numericConstant() {
			return getRuleContext(NumericConstantContext.class,0);
		}
		public NumericVariableContext numericVariable() {
			return getRuleContext(NumericVariableContext.class,0);
		}
		public NumericAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericAtom; }
	}

	public final NumericAtomContext numericAtom() throws RecognitionException {
		NumericAtomContext _localctx = new NumericAtomContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_numericAtom);
		try {
			setState(191);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMERIC:
				enterOuterAlt(_localctx, 1);
				{
				setState(189);
				numericConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(190);
				numericVariable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NumericConstantContext extends ParserRuleContext {
		public TerminalNode NUMERIC() { return getToken(formulaParser.NUMERIC, 0); }
		public NumericConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericConstant; }
	}

	public final NumericConstantContext numericConstant() throws RecognitionException {
		NumericConstantContext _localctx = new NumericConstantContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_numericConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(193);
			match(NUMERIC);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NumericVariableContext extends ParserRuleContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public NumericVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericVariable; }
	}

	public final NumericVariableContext numericVariable() throws RecognitionException {
		NumericVariableContext _localctx = new NumericVariableContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_numericVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(195);
			match(LT);
			setState(196);
			variable();
			setState(197);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(formulaParser.LPAREN, 0); }
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(formulaParser.RPAREN, 0); }
		public TerminalNode LCPAREN() { return getToken(formulaParser.LCPAREN, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public TerminalNode RCPAREN() { return getToken(formulaParser.RCPAREN, 0); }
		public StringAtomContext stringAtom() {
			return getRuleContext(StringAtomContext.class,0);
		}
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_string);
		try {
			setState(209);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
				enterOuterAlt(_localctx, 1);
				{
				setState(199);
				match(LPAREN);
				setState(200);
				string();
				setState(201);
				match(RPAREN);
				}
				break;
			case LCPAREN:
				enterOuterAlt(_localctx, 2);
				{
				setState(203);
				match(LCPAREN);
				setState(204);
				constant();
				setState(205);
				match(RCPAREN);
				setState(206);
				string();
				}
				break;
			case STRING:
			case LT:
				enterOuterAlt(_localctx, 3);
				{
				setState(208);
				stringAtom();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringAtomContext extends ParserRuleContext {
		public StringConstantContext stringConstant() {
			return getRuleContext(StringConstantContext.class,0);
		}
		public StringVariableContext stringVariable() {
			return getRuleContext(StringVariableContext.class,0);
		}
		public StringAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringAtom; }
	}

	public final StringAtomContext stringAtom() throws RecognitionException {
		StringAtomContext _localctx = new StringAtomContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_stringAtom);
		try {
			setState(213);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case STRING:
				enterOuterAlt(_localctx, 1);
				{
				setState(211);
				stringConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(212);
				stringVariable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringConstantContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(formulaParser.STRING, 0); }
		public StringConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringConstant; }
	}

	public final StringConstantContext stringConstant() throws RecognitionException {
		StringConstantContext _localctx = new StringConstantContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_stringConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			match(STRING);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringVariableContext extends ParserRuleContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public StringVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringVariable; }
	}

	public final StringVariableContext stringVariable() throws RecognitionException {
		StringVariableContext _localctx = new StringVariableContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_stringVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(217);
			match(LT);
			setState(218);
			variable();
			setState(219);
			match(T__3);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantContext extends ParserRuleContext {
		public TerminalNode BINARY() { return getToken(formulaParser.BINARY, 0); }
		public TerminalNode NUMERIC() { return getToken(formulaParser.NUMERIC, 0); }
		public TerminalNode BOOLEAN() { return getToken(formulaParser.BOOLEAN, 0); }
		public TerminalNode STRING() { return getToken(formulaParser.STRING, 0); }
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_constant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(221);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << NUMERIC) | (1L << BINARY) | (1L << BOOLEAN) | (1L << STRING))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableContext extends ParserRuleContext {
		public TerminalNode VARIABLE() { return getToken(formulaParser.VARIABLE, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_variable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(223);
			match(VARIABLE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Upper_boundContext extends ParserRuleContext {
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public Upper_boundContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_upper_bound; }
	}

	public final Upper_boundContext upper_bound() throws RecognitionException {
		Upper_boundContext _localctx = new Upper_boundContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_upper_bound);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(225);
			constant();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Lower_boundContext extends ParserRuleContext {
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public Lower_boundContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lower_bound; }
	}

	public final Lower_boundContext lower_bound() throws RecognitionException {
		Lower_boundContext _localctx = new Lower_boundContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_lower_bound);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(227);
			constant();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RelopContext extends ParserRuleContext {
		public TerminalNode GT() { return getToken(formulaParser.GT, 0); }
		public TerminalNode GE() { return getToken(formulaParser.GE, 0); }
		public TerminalNode LT() { return getToken(formulaParser.LT, 0); }
		public TerminalNode LE() { return getToken(formulaParser.LE, 0); }
		public RelopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relop; }
	}

	public final RelopContext relop() throws RecognitionException {
		RelopContext _localctx = new RelopContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_relop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(229);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << GT) | (1L << GE) | (1L << LT) | (1L << LE))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return boolean_sempred((BooleanContext)_localctx, predIndex);
		case 5:
			return logic_sempred((LogicContext)_localctx, predIndex);
		case 9:
			return numeric_sempred((NumericContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean boolean_sempred(BooleanContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 12);
		case 1:
			return precpred(_ctx, 8);
		case 2:
			return precpred(_ctx, 4);
		case 3:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean logic_sempred(LogicContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 6);
		case 5:
			return precpred(_ctx, 5);
		case 6:
			return precpred(_ctx, 4);
		case 7:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean numeric_sempred(NumericContext _localctx, int predIndex) {
		switch (predIndex) {
		case 8:
			return precpred(_ctx, 3);
		case 9:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3#\u00ea\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\3\2\3\2\3\2\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3`\n\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\7\3n\n\3\f\3\16\3q\13\3\3\4\3\4\5\4u\n\4\3\5"+
		"\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\5\7\u008b\n\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\7"+
		"\7\u0099\n\7\f\7\16\7\u009c\13\7\3\b\3\b\5\b\u00a0\n\b\3\t\3\t\3\n\3\n"+
		"\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u00b3"+
		"\n\13\3\13\3\13\3\13\3\13\3\13\3\13\7\13\u00bb\n\13\f\13\16\13\u00be\13"+
		"\13\3\f\3\f\5\f\u00c2\n\f\3\r\3\r\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3"+
		"\17\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u00d4\n\17\3\20\3\20\5\20\u00d8"+
		"\n\20\3\21\3\21\3\22\3\22\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\26"+
		"\3\26\3\27\3\27\3\27\2\5\4\f\24\30\2\4\6\b\n\f\16\20\22\24\26\30\32\34"+
		"\36 \"$&(*,\2\6\3\2\24\25\3\2\22\23\3\2\16\21\3\2\26\31\2\u00f5\2.\3\2"+
		"\2\2\4_\3\2\2\2\6t\3\2\2\2\bv\3\2\2\2\nx\3\2\2\2\f\u008a\3\2\2\2\16\u009f"+
		"\3\2\2\2\20\u00a1\3\2\2\2\22\u00a3\3\2\2\2\24\u00b2\3\2\2\2\26\u00c1\3"+
		"\2\2\2\30\u00c3\3\2\2\2\32\u00c5\3\2\2\2\34\u00d3\3\2\2\2\36\u00d7\3\2"+
		"\2\2 \u00d9\3\2\2\2\"\u00db\3\2\2\2$\u00df\3\2\2\2&\u00e1\3\2\2\2(\u00e3"+
		"\3\2\2\2*\u00e5\3\2\2\2,\u00e7\3\2\2\2./\5\4\3\2/\60\7\2\2\3\60\3\3\2"+
		"\2\2\61\62\b\3\1\2\62\63\7\13\2\2\63\64\5\4\3\2\64\65\7\f\2\2\65`\3\2"+
		"\2\2\66\67\7\t\2\2\678\5$\23\289\7\n\2\29:\5\4\3\22:`\3\2\2\2;<\7\"\2"+
		"\2<`\5\4\3\21=>\5\f\7\2>?\5,\27\2?@\5\f\7\2@`\3\2\2\2AB\5\24\13\2BC\5"+
		",\27\2CD\5\24\13\2D`\3\2\2\2EF\5\f\7\2FG\7\32\2\2GH\5\f\7\2H`\3\2\2\2"+
		"IJ\5\24\13\2JK\7\32\2\2KL\5\24\13\2L`\3\2\2\2MN\5\34\17\2NO\7\32\2\2O"+
		"P\5\34\17\2P`\3\2\2\2QR\5\f\7\2RS\7\33\2\2ST\5\f\7\2T`\3\2\2\2UV\5\24"+
		"\13\2VW\7\33\2\2WX\5\24\13\2X`\3\2\2\2YZ\5\34\17\2Z[\7\33\2\2[\\\5\34"+
		"\17\2\\`\3\2\2\2]`\5\6\4\2^`\5\f\7\2_\61\3\2\2\2_\66\3\2\2\2_;\3\2\2\2"+
		"_=\3\2\2\2_A\3\2\2\2_E\3\2\2\2_I\3\2\2\2_M\3\2\2\2_Q\3\2\2\2_U\3\2\2\2"+
		"_Y\3\2\2\2_]\3\2\2\2_^\3\2\2\2`o\3\2\2\2ab\f\16\2\2bc\7\32\2\2cn\5\4\3"+
		"\17de\f\n\2\2ef\7\33\2\2fn\5\4\3\13gh\f\6\2\2hi\7 \2\2in\5\4\3\7jk\f\5"+
		"\2\2kl\7!\2\2ln\5\4\3\6ma\3\2\2\2md\3\2\2\2mg\3\2\2\2mj\3\2\2\2nq\3\2"+
		"\2\2om\3\2\2\2op\3\2\2\2p\5\3\2\2\2qo\3\2\2\2ru\5\b\5\2su\5\n\6\2tr\3"+
		"\2\2\2ts\3\2\2\2u\7\3\2\2\2vw\7\20\2\2w\t\3\2\2\2xy\7\30\2\2yz\5&\24\2"+
		"z{\7\3\2\2{\13\3\2\2\2|}\b\7\1\2}~\7\13\2\2~\177\5\f\7\2\177\u0080\7\f"+
		"\2\2\u0080\u008b\3\2\2\2\u0081\u0082\7\t\2\2\u0082\u0083\5$\23\2\u0083"+
		"\u0084\7\n\2\2\u0084\u0085\5\f\7\n\u0085\u008b\3\2\2\2\u0086\u0087\7\37"+
		"\2\2\u0087\u008b\5\f\7\t\u0088\u008b\5\16\b\2\u0089\u008b\5\24\13\2\u008a"+
		"|\3\2\2\2\u008a\u0081\3\2\2\2\u008a\u0086\3\2\2\2\u008a\u0088\3\2\2\2"+
		"\u008a\u0089\3\2\2\2\u008b\u009a\3\2\2\2\u008c\u008d\f\b\2\2\u008d\u008e"+
		"\t\2\2\2\u008e\u0099\5\f\7\t\u008f\u0090\f\7\2\2\u0090\u0091\t\3\2\2\u0091"+
		"\u0099\5\f\7\b\u0092\u0093\f\6\2\2\u0093\u0094\7\34\2\2\u0094\u0099\5"+
		"\f\7\7\u0095\u0096\f\5\2\2\u0096\u0097\7\35\2\2\u0097\u0099\5\f\7\6\u0098"+
		"\u008c\3\2\2\2\u0098\u008f\3\2\2\2\u0098\u0092\3\2\2\2\u0098\u0095\3\2"+
		"\2\2\u0099\u009c\3\2\2\2\u009a\u0098\3\2\2\2\u009a\u009b\3\2\2\2\u009b"+
		"\r\3\2\2\2\u009c\u009a\3\2\2\2\u009d\u00a0\5\20\t\2\u009e\u00a0\5\22\n"+
		"\2\u009f\u009d\3\2\2\2\u009f\u009e\3\2\2\2\u00a0\17\3\2\2\2\u00a1\u00a2"+
		"\7\17\2\2\u00a2\21\3\2\2\2\u00a3\u00a4\7\30\2\2\u00a4\u00a5\5&\24\2\u00a5"+
		"\u00a6\7\4\2\2\u00a6\23\3\2\2\2\u00a7\u00a8\b\13\1\2\u00a8\u00a9\7\13"+
		"\2\2\u00a9\u00aa\5\24\13\2\u00aa\u00ab\7\f\2\2\u00ab\u00b3\3\2\2\2\u00ac"+
		"\u00ad\7\t\2\2\u00ad\u00ae\5$\23\2\u00ae\u00af\7\n\2\2\u00af\u00b0\5\24"+
		"\13\6\u00b0\u00b3\3\2\2\2\u00b1\u00b3\5\26\f\2\u00b2\u00a7\3\2\2\2\u00b2"+
		"\u00ac\3\2\2\2\u00b2\u00b1\3\2\2\2\u00b3\u00bc\3\2\2\2\u00b4\u00b5\f\5"+
		"\2\2\u00b5\u00b6\t\2\2\2\u00b6\u00bb\5\24\13\6\u00b7\u00b8\f\4\2\2\u00b8"+
		"\u00b9\t\3\2\2\u00b9\u00bb\5\24\13\5\u00ba\u00b4\3\2\2\2\u00ba\u00b7\3"+
		"\2\2\2\u00bb\u00be\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd"+
		"\25\3\2\2\2\u00be\u00bc\3\2\2\2\u00bf\u00c2\5\30\r\2\u00c0\u00c2\5\32"+
		"\16\2\u00c1\u00bf\3\2\2\2\u00c1\u00c0\3\2\2\2\u00c2\27\3\2\2\2\u00c3\u00c4"+
		"\7\16\2\2\u00c4\31\3\2\2\2\u00c5\u00c6\7\30\2\2\u00c6\u00c7\5&\24\2\u00c7"+
		"\u00c8\7\5\2\2\u00c8\33\3\2\2\2\u00c9\u00ca\7\13\2\2\u00ca\u00cb\5\34"+
		"\17\2\u00cb\u00cc\7\f\2\2\u00cc\u00d4\3\2\2\2\u00cd\u00ce\7\t\2\2\u00ce"+
		"\u00cf\5$\23\2\u00cf\u00d0\7\n\2\2\u00d0\u00d1\5\34\17\2\u00d1\u00d4\3"+
		"\2\2\2\u00d2\u00d4\5\36\20\2\u00d3\u00c9\3\2\2\2\u00d3\u00cd\3\2\2\2\u00d3"+
		"\u00d2\3\2\2\2\u00d4\35\3\2\2\2\u00d5\u00d8\5 \21\2\u00d6\u00d8\5\"\22"+
		"\2\u00d7\u00d5\3\2\2\2\u00d7\u00d6\3\2\2\2\u00d8\37\3\2\2\2\u00d9\u00da"+
		"\7\21\2\2\u00da!\3\2\2\2\u00db\u00dc\7\30\2\2\u00dc\u00dd\5&\24\2\u00dd"+
		"\u00de\7\6\2\2\u00de#\3\2\2\2\u00df\u00e0\t\4\2\2\u00e0%\3\2\2\2\u00e1"+
		"\u00e2\7\r\2\2\u00e2\'\3\2\2\2\u00e3\u00e4\5$\23\2\u00e4)\3\2\2\2\u00e5"+
		"\u00e6\5$\23\2\u00e6+\3\2\2\2\u00e7\u00e8\t\5\2\2\u00e8-\3\2\2\2\20_m"+
		"ot\u008a\u0098\u009a\u009f\u00b2\u00ba\u00bc\u00c1\u00d3\u00d7";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}