import pyparsing
from pyparsing import *

identifier = Word(alphas)
operator = Forward()
function_define_operator = 'def' + identifier('func_name') + Optional(Suppress(':') + identifier('type')) + Suppress('{') + ZeroOrMore(operator) + Suppress('}') + Suppress(';') 
operator << Word(alphas + ' \t') + Suppress(';')
source = 'module' + identifier('module_name') + Suppress(';') + ZeroOrMore(Group(function_define_operator))

print source.parseString('''
module hello;

def func : string { 
	rtre; 
	dsfer; 
	return 				dds;
};

def funci { 
	rtre; 
	dsfer; 
};
'''
)

'''
class EvalConstant(object):
    "Class to evaluate a parsed constant or variable"
    vars_ = {}
    def __init__(self, tokens):
        self.value = tokens[0]
    def eval(self):
        if self.value in EvalConstant.vars_:
            return EvalConstant.vars_[self.value]
        else:
            return float(self.value)

class EvalSignOp(object):
    "Class to evaluate expressions with a leading + or - sign"
    def __init__(self, tokens):
        self.sign, self.value = tokens[0]
    def eval(self):
        mult = {'+':1, '-':-1}[self.sign]
        return mult * self.value.eval()

def operatorOperands(tokenlist):
    "generator to extract operators and operands in pairs"
    it = iter(tokenlist)
    while 1:
        try:
            yield (it.next(), it.next())
        except StopIteration:
            break
            
class EvalMultOp(object):
    "Class to evaluate multiplication and division expressions"
    def __init__(self, tokens):
        self.value = tokens[0]
    def eval(self):
        prod = self.value[0].eval()
        for op,val in operatorOperands(self.value[1:]):
            if op == '*':
                prod *= val.eval()
            if op == '/':
                prod /= val.eval()
        return prod
    
class EvalAddOp(object):
    "Class to evaluate addition and subtraction expressions"
    def __init__(self, tokens):
        self.value = tokens[0]
    def eval(self):
        sum = self.value[0].eval()
        for op,val in operatorOperands(self.value[1:]):
            if op == '+':
                sum += val.eval()
            if op == '-':
                sum -= val.eval()
        return sum

integer = Word(pyparsing.nums)
real = Combine(Word(pyparsing.nums) + '.' + Word(pyparsing.nums))
operand = real | integer 

multop = pyparsing.oneOf('* /')
plusop = pyparsing.oneOf('+ -')

operand.setParseAction(EvalConstant)
arith_expr = operatorPrecedence(operand,
    [
     (multop, 2, opAssoc.LEFT, EvalMultOp),
     (plusop, 2, opAssoc.LEFT, EvalAddOp),
    ])
print arith_expr.parseString('2')[0].eval()
#expr = '343443'
'''

#def main():
#	pass

#if __name__ == '__main__':
#	main()