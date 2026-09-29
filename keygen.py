import hashlib
import sys

def generate_key(hwid_str):
    # 1. Переводим HWID строку в байты (как они лежат в памяти в виде PSN)
    psn_bytes = hwid_str.encode('utf-8')
    
    # 2. Считаем стандартный MD5 хэш
    md5_hash = hashlib.md5(psn_bytes).digest()
    
    # 3. Разворачиваем байты задом наперед (аналог цикла 0xf - i в Ghidra)
    reversed_digest = md5_hash[::-1]
    
    # 4. Превращаем обратно в HEX-строку нижнего регистра (%02x)
    license_key = reversed_digest.hex()
    return license_key

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Использование: python3 keygen.py <ВАШ_HWID>")
        sys.exit(1)
        
    hwid = sys.argv[1].upper() # Приводим к верхнему регистру
    key = generate_key(hwid)
    print(f"HWID: {hwid}")
    print(f"КЛЮЧ: {key}")

