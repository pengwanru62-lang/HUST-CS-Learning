from sympy import symbols, Or, Not, true

try:
    from sympy.logic.inference import satisfiable
except Exception:
    try:
        from sympy.logic.algorithms.dpll import dpll_satisfiable as satisfiable
    except Exception:
        satisfiable = None

def prove_resolution_principle():
    """
    验证归结原理的有效性。
    结构：
      前提1: P | Q
      前提2: ~P | R
      结论:  Q | R
    """
    P, Q, R = symbols('P Q R')

    # 用于计算的前提与结论表达式
    premise1 = Or(P, Q)
    premise2 = Or(Not(P), R)
    conclusion = Or(Q, R)

    # ---------- START ----------
    premises_conj = premise1 & premise2
    inference_expr = premises_conj >> conclusion
    if satisfiable(inference_expr):
        is_valid = True
    else:
        is_valid = False
    # ----------  END  ----------

    # —— 按题面要求的固定字符串格式输出 —— #
    print("前提: P | Q, R | ~P")
    print("结论: Q | R")
    print(f"归结原理是否有效: {is_valid}")

# 调用函数
if __name__ == "__main__":
    prove_resolution_principle()
