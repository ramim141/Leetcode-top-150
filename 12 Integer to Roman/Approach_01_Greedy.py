def intToRoman(num: int) -> str:
    # বড় থেকে ছোট ক্রমে মান এবং প্রতীক
    values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    
    result = []
    
    # প্রতিটি মানের জন্য লুপ চালাই
    for i in range(len(values)):
        # যতক্ষণ বর্তমান মান num-এর মধ্যে থাকবে
        while num >= values[i]:
            # num থেকে মানটি বিয়োগ করি
            num -= values[i]
            # এবং সংশ্লিষ্ট প্রতীক ফলাফলে যোগ করি
            result.append(symbols[i])
            
    return "".join(result)