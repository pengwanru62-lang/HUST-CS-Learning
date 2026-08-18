from sympy import symbols,true

try:
    from sympy.logic.inference import satisfiable
except Exception:
    try:
        from sympy.logic.algorithms.dpll import dpll_satisfiable as satisfiable
    except Exception:
        satisfiable = None

def find_fallacy_counterexample():
    """
    证明“肯定后件”是无效推理，并找到一个反例。
    """
    P, Q = symbols('P Q')
    
    # 定义前提和结论（用于计算）
    premise1 = P >> Q
    premise2 = Q
    conclusion = P

    # ---------- START ----------
    # 1) 构造前提合取 premises_conj
    premises_conj = premise1 & premise2
    # 2) 使用 satisfiable 判断 is_valid
    inference_expr = premises_conj >> conclusion
    if ~inference_expr.equals(true):
        is_valid = False
    else:
        is_valid = True
    # 3) 使用 satisfiable 求一个反例模型 model
    premises_conj = premise1 & premise2 
    counterexample_formula = premises_conj & ~conclusion
    model = satisfiable(counterexample_formula)
    # ----------  END  ----------

    # —— 按题面要求的固定字符串格式输出 —— #
    print("推理: 如果 (P >> Q) 且 Q, 那么 P")
    print(f"该推理是否有效: {is_valid}\n")

    # 规范化反例输出顺序为 {Q: True, P: False}
    if model:
        # 有的 satisfiable 返回 False；有的返回 dict
        q_val = bool(model.get(Q, False)) if isinstance(model, dict) else True
        p_val = bool(model.get(P, False)) if isinstance(model, dict) else False
        counterexample = {Q: q_val, P: p_val}
        print(f"找到一个反例 (使前提为真，结论为假的赋值): {{Q: {q_val}, P: {p_val}}}")
        print(f"在反例下，前提1结果: {premise1.subs(counterexample)}")
        print(f"在反例下，前提2结果: {premise2.subs(counterexample)}")
        print(f"在反例下，结论结果: {conclusion.subs(counterexample)}")
    else:
        print("未找到反例，这说明推理是有效的。")

# 调用函数
if __name__ == "__main__":
    find_fallacy_counterexample()
