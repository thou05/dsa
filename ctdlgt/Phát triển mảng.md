Created: 202409220519
Tags: 

Khi thực hiện phép toán, nếu mảng đầy => xảy ra lỗi. 
Để có thể thêm phần tử => mở rộng mảng

#### Chiến lược phát triển theo hằng số
Khi mảng cần mở rộng, kích thước của mảng mới được tăng thêm một số lượng cố định (c) phần tử.

Ưu:
- Dễ dàng cài đặt: chỉ cần thêm 1 số phần tử cố định
- Dễ dự đoán kích thước
Nhược:
- Hiệu suất kém: thao tác mở rộng mảng có thể xảy ra thường xuyên hơn => nhiều thao tác sao chép 
- Lãng phí tài nguyên bộ nhớ: do  khi mảng mở rộng có thể cấp phát nhiều bộ nhớ hơn cần thiết

#### Chiến lược gấp đôi
Khi mảng cần mở rộng, kích thước của mảng mới được gấp đôi so với kích thước hiện tại.

Ưu:
- Hiệu suất tốt hơn: giảm số lần mở rộng mảng cần thiết
- Tối ưu hóa tài nguyên: mảng sẽ có kích thước lớn hơn càn thiết => ít lãng phí bộ nhớ hơn
Nhược:
- Cài đặt phức tạp hơn: cần phải tinh toán kích thước mới của mảng mỗi lần mở rộng
- Sự lãng phí đôi lúc tạo mảng: mặc dù tiết kiệm bộ nhớ tổng thể, nhưng mỗi lần mở rộng cấp phát lượng bộ nhớ lớn hơn gần thiết => lãng phí bộ nhớ tạm thời
Nên sử dụng chiến lược này

-----
## References
1. [[DSA]]
2. [[Vector]]
