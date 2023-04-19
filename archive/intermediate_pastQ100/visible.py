import os
import re

# ディレクトリを指定
directory = "C:/programming/atcoder/archive/intermediate_pastQ100"

# 1から100までのフラグを初期化
flags = [False] * 100

# ディレクトリ内のファイル名を取得
for filename in os.listdir(directory):
    try:
        match = re.match(r"(\d+).*\.cpp", filename)
        if match:
            number = int(match.group(1))
            if 1 <= number <= 100:
                flags[number - 1] = True
    except ValueError:
        continue

# フラグを10x10配列でMarkdownファイルに保存
with open("README.md", "w", encoding='utf-8') as f:
    f.write("競技プログラミングのアーカイブ\n\n")
    f.write("## 過去問精選100問 進行状況\n\n")
    f.write("|       | Status |       | Status |       | Status |       | Status |       | Status |\n")
    f.write("|:-----:|:------:|:-----:|:------:|:-----:|:------:|:-----:|:------:|:-----:|:------:|\n")
    
    for i in range(0, 100, 10):
        for j in range(1, 11):
            index = i + j
            if j == 1:
                f.write("|")
            f.write(f" {index:3} | {'✓' if flags[index - 1] else '&nbsp;'} |")
        if i == 90:
            f.write(" &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; |\n")
        else:
            f.write("\n")
