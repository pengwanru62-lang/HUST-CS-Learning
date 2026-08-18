def symbolize_existential_facts():
    """
    将用于AI知识库的具体事实（自然语言）进行符号化。
    """
    # 事实1: “有些机器人会编程。”
    # 定义谓词:
    # R(x): x是机器人
    # P(x): x会编程

    # 平台将测试你补全的代码
    # ---------- START ----------
    fact1_symbolic = "exists x, R(x) & P(x)"
    # ----------  END  ----------

    print("事实1: “有些机器人会编程。”")
    print(f"符号化表示: {fact1_symbolic}\n")

    # 事实2: “并非所有金属都能导电。”
    # 定义谓词:
    # M(x): x是金属
    # C(x): x能导电

    # ---------- START ----------
    fact2_symbolic = "exists x, M(x) & ~C(x)"
    # ----------  END  ----------

    print("事实2: “并非所有金属都能导电。”")
    print(f"符号化表示: {fact2_symbolic}")

# 调用函数
symbolize_existential_facts()