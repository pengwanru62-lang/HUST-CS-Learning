def symbolize_universal_rules():
    """
    将用于AI知识库的普遍规则（自然语言）进行符号化。
    """
    # 规则1: “所有的矩形都是四边形。”
    # 定义谓词:
    # R(x): x是矩形
    # Q(x): x是四边形

    # ---------- START ----------
    rule1_symbolic = "forall x, R(x) >> Q(x)"
    # ----------  END  ----------

    print("规则1: “所有的矩形都是四边形。”")
    print(f"符号化表示: {rule1_symbolic}\n")

    # 规则2: “没有不遵守交通规则的司机。”
    # 定义谓词:
    # D(x): x是司机
    # T(x): x遵守交通规则

    # ---------- START ----------
    rule2_symbolic = "forall x, D(x) >> T(x)"
    # ----------  END  ----------

    print("规则2: “没有不遵守交通规则的司机。”")
    print(f"符号化表示: {rule2_symbolic}")

# 调用函数
symbolize_universal_rules()