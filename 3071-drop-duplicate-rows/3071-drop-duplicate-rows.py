import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    # Drop duplicate rows based on the 'email' column, keeping the first occurrence
    customers = customers.drop_duplicates(subset=['email'], keep='first')
    
    return customers
