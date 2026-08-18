from sympy import symbols

try:
    from sympy.logic.inference import satisfiable
except Exception:
    try:
        from sympy.logic.algorithms.dpll import dpll_satisfiable as satisfiable
    except Exception:
        satisfiable = None  

def prove_constructive_dilemma():
    """
    验证构造性二难推理的有效性，并按题面格式输出。
    """

    P, Q, R, S_ = symbols('P Q R S')

    # 用于验证的 SymPy 表达式
    premise1 = P >> Q
    premise2 = R >> S_
    premise3 = P | R
    conclusion = Q | S_


    # ---------- START ----------
    premises_conj = premise1 & premise2 & premise3
    inference_expr = premises_conj >> conclusion
    if satisfiable(inference_expr):
        is_valid = True
    else:
        is_valid = False
    # ----------  END  ----------

    # —— 按题面要求的字符串格式输出 —— #
    print(f"前提: P >> Q, R >> S, P | R")
    print(f"结论: Q | S")
    print(f"构造性二难推理是否有效: {is_valid}")

# 调用函数
if __name__ == "__main__":
    prove_constructive_dilemma()
