#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
#include <algorithm>

class Node {
public:
    virtual double evaluate(const std::vector<std::pair<std::string, double>>& context) const = 0;
    virtual ~Node() = default;
};

class NumberNode : public Node {
    double value;
public:
    explicit NumberNode(double val) : value(val) {}
    double evaluate(const std::vector<std::pair<std::string, double>>&) const override {
        return value;
    }
};

class VariableNode : public Node {
    std::string name;
public:
    explicit VariableNode(const std::string& n) : name(n) {}
    double evaluate(const std::vector<std::pair<std::string, double>>& context) const override {
        for (auto& [var, val] : context)
            if (var == name)
                return val;
        throw std::runtime_error("Variable not found: " + name);
    }
};

class OperationNode : public Node {
public:
    std::string op;
    std::vector<Node*> args;

    explicit OperationNode(const std::string& op) : op(op) {}
    ~OperationNode() = default;

    void addArg(Node* node) { args.push_back(node); }

    double evaluate(const std::vector<std::pair<std::string, double>>& context) const override {
        std::vector<double> values;
        for (auto child : args)
            values.push_back(child->evaluate(context));

        if (op == "add") {
            if (values.size() != 2) throw std::runtime_error("add requires 2 args");
            return values[0] + values[1];
        } else if (op == "subtract") {
            if (values.size() != 2) throw std::runtime_error("subtract requires 2 args");
            return values[0] - values[1];
        } else if (op == "multiply") {
            if (values.size() != 2) throw std::runtime_error("multiply requires 2 args");
            return values[0] * values[1];
        } else if (op == "divide") {
            if (values.size() != 2) throw std::runtime_error("divide requires 2 args");
            if (values[1] == 0) throw std::runtime_error("Division by zero");
            return values[0] / values[1];
        } else if (op == "negate") {
            if (values.size() != 1) throw std::runtime_error("negate requires 1 arg");
            return -values[0];
        } else if (op == "max") {
            if (values.empty()) throw std::runtime_error("max requires >=1 arg");
            return *std::max_element(values.begin(), values.end());
        } else if (op == "min") {
            if (values.empty()) throw std::runtime_error("min requires >=1 arg");
            return *std::min_element(values.begin(), values.end());
        }

        throw std::runtime_error("Unknown operation: " + op);
    }
};

Node* parse(const std::string& expr) {
    std::stack<OperationNode*> stack;
    Node* root = nullptr;

    for (size_t i = 0; i < expr.size();) {
        if (isspace(expr[i])) { i++; continue; }

        if (isalpha(expr[i])) {
            std::string name;
            while (i < expr.size() && (isalpha(expr[i]) || isdigit(expr[i]) || expr[i] == '_'))
                name += expr[i++];

            if (i < expr.size() && expr[i] == '(') {
                OperationNode* opNode = new OperationNode(name);
                stack.push(opNode);
                i++;
            } else {
                Node* varNode = new VariableNode(name);
                if (!stack.empty())
                    stack.top()->addArg(varNode);
                else
                    root = varNode;
            }
        }

        else if (isdigit(expr[i]) || expr[i] == '.') {
            std::string num;
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.'))
                num += expr[i++];
            double val = std::stod(num);
            Node* numNode = new NumberNode(val);
            if (!stack.empty())
                stack.top()->addArg(numNode);
            else
                root = numNode;
        }

        else if (expr[i] == ',') {
            i++;
        }

        else if (expr[i] == ')') {
            if (stack.empty()) throw std::invalid_argument("Unmatched )");
            OperationNode* finished = stack.top();
            stack.pop();
            i++;

            if (!stack.empty())
                stack.top()->addArg(finished);
            else
                root = finished;
        }

        else {
            throw std::invalid_argument(std::string("Unexpected character: ") + expr[i]);
        }
    }

    if (!stack.empty()) throw std::invalid_argument("Unmatched (");
    if (!root) throw std::invalid_argument("Empty expression");

    return root;
}

void clear(Node* node) {
    if (!node) return;
    if (auto opNode = dynamic_cast<OperationNode*>(node)) {
        for (auto child : opNode->args)
            clear(child);
    }
    delete node;
}

int main() {
    std::vector<std::pair<std::string, double>> context = {
        {"x", 2.5},
        {"y", 12.0}
    };

    std::string expression = "multiply(add(x, 5.5), negate(max(y, 10, 4)))";

    try {
        Node* ast = parse(expression);
        double result = ast->evaluate(context);
        std::cout << "Result: " << result << std::endl;

        clear(ast);
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
