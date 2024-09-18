#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Expr{
	private:
	string expression;
	int precedence(char op){
		if(op=='+'||op=='-') return 1;
		if(op=='*'||op=='/') return 2;
		return 0;
	}
	
	int applyOp(int a, int b, char op){
		switch(op){
			case '+': return a+b;
			case '-': return a-b;
			case '*': return a*b;
			case '/': return a/b;
			default: return 0;
		}
	}
	
	string toPostfix(){
		stack<char> operators;
		string output;
		for(char token: expression){
			if(isdigit(token)){
				output += token;
				output += ' ';
			}else if(token == '+'||token == '-'||token == '*'||token == '/'){
				while(!operators.empty() && precedence(operators.top())>=precedence(token)){
					output += operators.top();
					output += ' ';
					operators.pop();
				}
				operators.push(token);
			}
		}
		while(!operators.empty()){
			output += operators.top();
			output += ' ';
			operators.pop();
		}
		return output;
	}

	int evalPostfix(const string& postfix){
		stack<int> values;
		for(int i=0;i<postfix.length();i++){
			char token = postfix[i];
			if(isdigit(token)){
				values.push(token - '0');
			}else if(token == '+'||token == '-'||token == '*'||token == '/'){
				int b = values.top(); values.pop();
				int a = values.top(); values.pop();
				values.push(applyOp(a,b,token));
			}
		}
		return values.top();
	}

	public:
	Expr(const char* expr) : expression(expr){}
	int eval(){
		string postfix = toPostfix();
		return evalPostfix(postfix);
	}
	void print(){
		cout<<expression<<endl;
	}
};

int main(){
	Expr x("8/4+3*4-3");
	cout<<"x = "<<x.eval()<<endl;
	x.print();
	return 0;
}
