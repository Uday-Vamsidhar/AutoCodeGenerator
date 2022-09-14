//auto code generator

//ideal method would use a file which would store the details entered, or the logic enetered.
//here we use vectors to accept a complete string (not ideal, but works for small scale)

#include<bits/stdc++.h>
using namespace std;

//library declaration
//this is common for all
void libraries()
{
    cout<<"#include<bits/stdc++.h>"<<endl;
    cout<<"using namespace std;"<<endl;
}

//Declare datatype when encountered
string declare(string datatype)
{
    if(datatype=="Integer")
        return "int ";
    else if(datatype=="Float")
        return "float ";
    return "double ";
}

// binary operations
string operations(string operate)
{
    string answer;
    if(operate=="Less")
        answer="<";
    else if(operate=="More")
        answer=">";
    else if(operate=="Equal")
        answer="==";
    else if(operate=="LessEqual")
        answer="<=";
    else if(operate=="MoreEqual")
        answer=">=";
    return answer;
}


// all math function which are needed for code
string math(string type, vector<string> var)
{
    string final="";
    if(type=="Sum")
    {
        for(int i=0;i<var.size();i++)
        {
            if(i==var.size()-1)
                final+=var[i];
            else
            {
                final+=var[i];
                final+="+";
            }
        }
    }
    else if(type=="Subtract")
    {
        for(int i=0;i<var.size();i++)
        {
            if(i==var.size()-1)
                final+=var[i];
            else
            {
                final+=var[i];
                final+="-";
            }
        }
    }
    else if(type=="Multiply")
    {
        for(int i=0;i<var.size();i++)
        {
            if(i==var.size()-1)
                final+=var[i];
            else
            {
                final+=var[i];
                final+="*";
            }
        }
    }
    else if(type=="Divide")
    {
        for(int i=0;i<var.size();i++)
        {
            if(i==var.size()-1)
                final+=var[i];
            else
            {
                final+=var[i];
                final+="/";
            }
        }
    }
    else if(type=="Modulo")
    {
        for(int i=0;i<var.size();i++)
        {
            if(i==var.size()-1)
                final+=var[i];
            else
            {
                final+=var[i];
                final+="%";
            }
        }
    }
    return final;    
}

//functional magic
void function_maker(string accept)
{
    //base function and parenthesis
    cout<<"int main()"<<endl;
    cout<<"{"<<endl;
    
    string split="";
    vector<string> words;
    
    //the string is split into each word accessible
    for(int i=0;i<accept.length();i++)
    {
        if(accept[i]!=' ')
            split+=accept[i];
            
        else if(accept[i]==' ')
        {
            words.push_back(split);
            split="";
        }
    }
    string temp="";
    temp=accept[accept.length()-1];
    words.push_back(temp);
    
    vector<string> result;
    vector<string> variables;
    
    //for each vector element, there will be a corresponding output
    for(int i=0;i<words.size();i++)
    {
        if(words[i]=="Declare")
        {
            result.push_back(declare(words[i+1]));
            for(int j=i+2;j<words.size();j++)
            {
                if(words[j]=="/"||words[j].size()>1)
                    break;
                else
                {
                    variables.push_back(words[j]);
                    result.push_back(words[j]);
                    if(words[j+1]!="/"&&words[j+1].size()==1)
                        result.push_back(",");
                }
            }
            result.push_back(";");
        }
        
        else if(words[i]=="If")
        {
            int k=i;
            result.push_back("if");
            result.push_back("(");
            for(int j=k+1;j<words.size();j++)
            {
                if(words[j]=="Then")
                    break;
                else if(words[j].length()!=1)
                    result.push_back(operations(words[j]));
                else 
                    result.push_back(words[j]);
            }
            result.push_back(")\n");
            result.push_back("{\n");
        }
        else if(words[i]=="EndIf")
            result.push_back("}");
        
        else if(words[i]=="Return")
            result.push_back("return ");
            
        else if(words[i]=="Print")
        {
            result.push_back("cout<<");
            if(i!=words.size()-1)
            {
                if(words[i]=="Sum"||words[i]=="Subtract"||words[i]=="Multiply"||words[i]=="Divide"||words[i]=="Modulo")
                {
                    result.push_back(math(words[i],variables));
                    result.push_back(";");
                }
            }
        }
        
        else if(words[i]=="Break")
        {
            result.push_back("break");
            result.push_back(";");
        }
        
        else if(words[i]=="Contniue")
        {
            result.push_back("contniue");
            result.push_back(";");
        }
        
        else if(words[i]=="Sum"||words[i]=="Subtract"||words[i]=="Multiply"||words[i]=="Divide"||words[i]=="Modulo")
        {
            result.push_back(math(words[i],variables));
            result.push_back(";");
        }
    }
    
    //print the results
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i];
        if(result[i]==";")
            cout<<endl;
    }
}

//flow control
int main()
{
    //to accept the algorithm written by the user
    string accept;
    getline(cin,accept);
    
    cout<<endl;
    
    //calling the magic
    libraries();
    function_maker(accept);
    
    //end parenthesis
    cout<<"\n}";
}