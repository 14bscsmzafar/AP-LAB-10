#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

class stack
{
public:
	stack(int);
	~stack();
	void push(char);
	char pop();
	bool isfull();
	bool isEmpty();
	void clear();
	char peek();
private:
	char* arr;
	int count;
	int size;
};

stack::stack(int Inpsize=50) //default value is 50
{
	arr = new char[Inpsize];
	count = -1;
	size = Inpsize;
}

stack::~stack()
{
	delete[] arr;
}
bool stack::isfull()
{
	return count == (size - 1);
}
bool stack::isEmpty()
{
	return count == -1;
}
void stack::push(char element)
{
	if (!isfull())
		arr[++count] = element;
	else
		cout << "The stack is full!" << endl;
}
char stack::pop()
{
	if (!isEmpty())
		return arr[count--];
	else
	{
		cout << "The stack is empty" << endl;
		return '\0';
	}
}
void stack::clear()
{
	delete[] arr;
}
char stack::peek()
{
	if (!isEmpty())
		return arr[count];
	else
	{
		cout << "The stack is empty" << endl;
		return '\0';
	}
}

int validate(string expression, int ArrSize)
{
	stack parenthesis(ArrSize);
	int StrSize = 0;
	StrSize = expression.size();
	char temp, temp2;

	for (int i = 0; i < StrSize; i++)
	{
		temp=expression.at(i);
		switch (temp)
		{
		case '(':
		case' {':
		case '[':
			parenthesis.push(temp);
			break;
		case ')':
			if (parenthesis.pop() != '(')
			{
				cout << "The equation is invalid!" << endl << "The bracket: " << expression.at(i) << " is wrongly closed! Index no: " << i+1<< endl;
				return -1;
			}
			break;
		case '}':
			if (parenthesis.pop() != '{')
			{
				cout << "The equation is invalid!" << endl << "The bracket: " << expression.at(i) << " is wrongly closed! Index no: " << i+1 << endl;
				return -1;
			}
			break;
		case ']':
			if (parenthesis.pop() != '[')
			{
				cout << "The equation is invalid!" << endl << "The bracket: " << expression.at(i) << " is wrongly closed! Index no: " << i+1 << endl;
				return -1;
			}
			break;
		default:
			break;
		}
	}

	if (!parenthesis.isEmpty())
	{
		temp2 = parenthesis.pop();
		for (int i = 0; i < StrSize; i++)
		{
			temp = expression.at(i);
			if (temp2 == temp)
			{
				cout << "The equation is invalid! \nThe bracket " << temp2 << " at " << i + 1 << " is not closed!" << endl;
				return -1;
			}
		}
	}

	return 1;
}
float determinat(float a, float b, float c)
{
	return ((b*b)-(4*a*c));
}

void quadratic(float a, float b, float c)
{
	float det=determinat(a,b,c);
	det=-1*det;
	cout << "Root 1: " << ((-1*b)+sqrt(det))/(2*a) << endl << "Root 2: " << ((-1*b) - sqrt(det))/(2*a) << endl;
}



void parseExp(string exp)
{
	float x3=0;
	float x2=0;
	float x1=0;
	float x0=0;
	
	float tempX;
	string temp;
	for (int i=0; i < exp.length(); i++)
	{
		while (exp[i]!='x' && i < exp.length() )
		{
			i++;
		}
		int j=i;
		
		if (exp[i]=='x')
		{
			if (j==0)
				tempX=1;
			else
			{
				j--;
				while(j >= 0)
				{
					if (isdigit(exp[j])|| exp[j] == '.')
						j--;
					else
						break;
					 
				}
				
				j++;
				temp="";
				for (j=j; j < i; j++)
				{
					temp+=exp[j];
				}
			}
			
			if (++i < exp.length())
			{
				if (exp[i]=='^')
				{
					i++;
					if (exp[i]== '3')
					{
						if (temp=="")
						{
							x3=1;
						}
						else
						{
						
							x3=atof(temp.c_str());
						}
					}
					else if (exp[i]=='2')
					{
						if (temp=="")
						{
							x2=1;
						}
						else
						{
						
							x2=atof(temp.c_str());
						}
					}
				}
				else 
				{
					if (temp=="")
						{
							x1=1;
						}
						else
						{
						
							x1=atof(temp.c_str());
						}
				}
			}
		
		}
	}
	
	bool powerZero=false;
	for (int i=0; i < exp.length(); i++)
	{
		if (isdigit(exp[i]))
		{
			temp="";
			while (i < exp.length())
			{
				if (isdigit(exp[i])||exp[i]=='.')
					{
						temp+=exp[i];
						i++;
						
					}
				else if (exp[i]=='x'||exp[i]=='^')
					break;
				else
				{
					powerZero=true;
					break;
				}
			}
			if (i==exp.length())
				powerZero=true;
			
		}
		
		if (powerZero)
		{
			x0=atof(temp.c_str());
			break;
		}
		else if (exp[i]=='^')
			i++;
			
	}
	cout << x3<< endl << x2 << endl << x1 << endl << x0<< endl;
	quadratic(x2, x1, x0);
}




void solveLinear(string exp)
{
	int cof=1;
	int i;
	int numIterator;
	for (i=0; i< exp.length(); i++)
	{
		if (exp[i]=='x')
		break;
	}
	numIterator = i-1;
	
	while (numIterator >= 0 && isdigit(exp[numIterator]) && exp[numIterator] != '=')
	{
		numIterator--;
	}
	numIterator++;
	string temp="";
	if (numIterator!=i-1)
	{
		
		for (int j=numIterator; j < i; j++)
			temp+=exp[j];
			
		cof = atoi(temp.c_str());
	}
	else 
	{
		if (isdigit(exp[numIterator]))
		{
			cof = exp[numIterator] - '0';
		}
			
	}
	
	cout << "num=" << cof<< endl;
	
	int leftTotal=0;
	int rightTotal=0;
	
	temp="";				
	bool left=true;
	string leftSide="";
	string rightSide="";
	for (i = 0; i < exp.length(); i++)
	{
		if (exp[i]=='=')
			left=false;
		if (left)
			leftSide += exp[i];
		else
			rightSide+=exp[i];
		
	}
	temp = "";
	char operation=NULL;
	int tempInt;
	bool xAtLeft=false;
	for (int j=0; j < leftSide.length(); j++)
	{
		if (isdigit(exp[j]))
			{
				temp="";
				while (isdigit(leftSide[j]) && j < leftSide.length())
				{
					temp+=leftSide[j];
					j++;
				}
				if (leftSide[j]=='x')
				{
					xAtLeft = true;
					j++;
					//continue;
				}
				else
				{
					tempInt = atoi(temp.c_str());
					if (operation == NULL)
					{
						leftTotal = tempInt;
					}
					else if (operation == '+')
					{
						leftTotal+=tempInt;
					}
					else if(operation == '-')
					{
						leftTotal-=tempInt;
					}
					else if(operation == '*')
					{
						leftTotal *=tempInt;
					}
				}
				
				if (j < leftSide.length())
					operation=leftSide[j];
			}
			
	}
	operation=NULL;
	for (int j=0; j < rightSide.length(); j++)
	{
		if (isdigit(rightSide[j]))
			{
				temp="";
				while (isdigit(rightSide[j]) && j < rightSide.length())
				{
					temp+=rightSide[j];
					j++;
				}
				if (rightSide[j]=='x')
				{
					//continue;
					j++;
				}
				else
				{
					tempInt = atoi(temp.c_str());
					if (operation == NULL)
					{
						rightTotal = tempInt;
					}
					else if (operation == '+')
					{
						rightTotal+=tempInt;
					}
					else if(operation == '-')
					{
						rightTotal-=tempInt;
					}
					else if(operation == '*')
					{
						rightTotal *=tempInt;
					}
				}
				
				if (j < rightSide.length())
					operation=rightSide[j];
			}
			
	}
	float ans=0;
	if (xAtLeft)
	{
		ans=(float)rightTotal - (float)leftTotal;
		ans=ans/(float)cof;
	}
	else
	{
		ans=(float)leftTotal - (float)rightTotal;
		ans=ans/(float)cof;
	}
	cout << "x = " << ans<< endl;
}
int linear()
{
	int inp=0;
	string expression;
	

	 
	cout << "Please enter the expression: ";
	cin >> expression;
		

	if (validate(expression, 100))
		solveLinear(expression);

	system("pause");
	return 0;
}
void quad()
{
	string inp;
	cout << "Please enter a expression: ";
	cin >> inp;
	
	if (validate(inp, 100))
		parseExp(inp);

	system("pause");	
} 

int main()
{
	quad();
	
	return 0;
		
	
}
