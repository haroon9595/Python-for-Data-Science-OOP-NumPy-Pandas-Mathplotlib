import pandas as pd  # 'pandas' correct hai, 'panda' nahi

df = pd.read_csv("sales_data_sample.csv", encoding="latin1")
print(df.head())