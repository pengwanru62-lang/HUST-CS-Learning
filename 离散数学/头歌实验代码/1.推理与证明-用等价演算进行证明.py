from sympy import symbols, Not, Implies, And
from sympy.logic.boolalg import simplify_logic

def prove_equivalence_by_simplification():
    """
    通过化简来证明 ~(P >> Q) <=> (P & ~Q)
    """
    P, Q = symbols('P Q')

    # 计算所用的表达式
    expr1 = Not(Implies(P, Q))     # ~(P >> Q)
    expr2 = And(P, Not(Q))         # P & ~Q
    
    # —— 按题面要求的固定字符串输出 —— #
    print("表达式1: ~(P >> Q)")
    print("表达式2: P & ~Q")

    # ---------- START ----------
    simplified_expr1 = simplify_logic(expr1)
    # ----------  END  ----------

    print(f"化简后的表达式1: {simplified_expr1}")
    print(f"化简结果是否与表达式2相等: {simplified_expr1 == expr2}")

# 调用函数
if __name__ == "__main__":
    prove_equivalence_by_simplification()