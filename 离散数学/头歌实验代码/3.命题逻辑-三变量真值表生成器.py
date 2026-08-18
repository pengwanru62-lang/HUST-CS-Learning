from sympy import symbols, sympify
from itertools import product

def truth_table_three_vars(expression_str):
    """
    生成并打印包含 P, Q, R 三个变量的逻辑表达式的真值表。

    参数:
    expression_str (str): 代表逻辑表达式的字符串. 例如: "(P | Q) >> R"
    """
    # 预先定义好命题变量
    P, Q, R = symbols('P Q R')

    try:
        # 将字符串安全地转换为sympy表达式
        expression = sympify(expression_str)
    except Exception as e:
        print(f"表达式错误: {e}")
        return

    # 打印表头
    print(f"真值表: {expression_str}")
    print("P\tQ\tR\t")
    print("-" * 30)

    # 平台将测试你补全的代码
    # ---------- START ----------
    # 使用 itertools.product 生成所有 P, Q, R 的组合
    for p_val, q_val, r_val in product([True, False], repeat=3):
        #创建字典储存结果
        subs_dict = {P: p_val, Q:q_val, R:r_val}
        #计算表达式的结果
        result = expression.subs(subs_dict)
        print(f"{p_val}\t{q_val}\t{r_val}\t{result}")
    # ----------  END  ----------

if __name__ == "__main__":
    import sys
    expr = sys.stdin.readline().strip()

    if len(expr) >= 2 and ((expr[0] == '"' and expr[-1] == '"') or (expr[0] == "'" and expr[-1] == "'")):
        expr = expr[1:-1]
    if not expr:
        print("表达式错误: 空输入")
    else:
        truth_table_three_vars(expr)
