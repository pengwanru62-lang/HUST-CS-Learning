from sympy import symbols, Equivalent, And, Or

try:
    from sympy.logic.inference import satisfiable
except Exception:
    try:
        from sympy.logic.algorithms.dpll import dpll_satisfiable as satisfiable
    except Exception:
        satisfiable = None


def verify_distributive_laws():
    P, Q, R = symbols('P Q R')


    # ---------- START ----------
    formula1 = And(P, Or(Q, R))
    formula2 = Or(And(P, Q), And(P, R))
    equiv_expr = Equivalent(formula1, formula2)
    is_tauto1 = not satisfiable(~equiv_expr)

    formula3 = Or(P, And(Q, R))
    formula4 = And(Or(P, Q), Or(P, R))
    equiv_expr1 = Equivalent(formula3, formula4)
    is_tauto2 = not satisfiable(~equiv_expr1)
    # ----------  END  ----------

    # —— 按题面要求的固定字符串输出 —— #
    print("待验证定律1: (P & (Q | R)) <=> ((P & Q) | (P & R))")
    print("待验证定律2: (P | (Q & R)) <=> ((P | Q) & (P | R))")
    print(f"定律1是否为重言式: {is_tauto1}")
    print(f"定律2是否为重言式: {is_tauto2}")

if __name__ == "__main__":
    verify_distributive_laws()
