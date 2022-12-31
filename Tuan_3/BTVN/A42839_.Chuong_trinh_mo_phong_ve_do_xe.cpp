/*
6. Chương trình mô phỏng vé đỗ xe 
Bạn cần thiết kế một tập các lớp có thể hoạt động cùng nhau giả lập một văn phòng cảnh sát chuyên quản lý 
vé đỗ xe. Các lớp bạn cần xây dựng là: 
ParkedCar: mô phỏng các xe đã đỗ, có nhiệm vụ lưu giữ thông tin hãng xe, model, màu sắc, mã số giấy phép, 
và thời gian xe đã đỗ tính bằng đơn vị phút. 
ParkingMeter: mô phỏng đồng hồ tính giờ đỗ xe, có nhiệm vụ lưu giữ thông tin thời gian đỗ xe mà chủ xe đã 
mua (chủ xe thường mua vé đỗ xe tương đương thời gian đỗ nào đó, nếu xe đỗ quá thời gian này mới tính là đỗ trái phép)  
ParkingTicket: mô phỏng vé đỗ xe, có các nhiệm vụ:  
    •	Báo cáo các thông tin hãng xe, model, màu sắc, và mã số giấy phép của chiếc xe đã đỗ trái phép. 
    •	Báo cáo số tiền phạt, với 25 đô la cho giờ đầu tiên (hoặc dưới một giờ đầu tiên) của chiếc xe đã đỗ 
    trái phép, cộng thêm 10 đô la cho mỗi giờ tiếp theo (hoặc dưới 1 giờ tiếp theo) của chiếc xe đã đỗ trái phép. 
    •	Báo cáo tên và số hiệu của cảnh sát xuất vé. 
    PoliceOfficer: mô phỏng một cảnh sát đang kiểm tra những chiếc xe ô tô đang đỗ. Nhiệm vụ của lớp này là: 
    •	Lưu giữ tên cảnh sách và số hiệu của cảnh sát. 
    •	Xem xét đối tượng ParkedCar, kiểm tra đối tượng ParkingMeter, và xác định xem thời 
    gian của xe ô tô đó đã hết hạn đỗ hay chưa. 
    •	Phạt vé đỗ xe (tạo ra một đối tượng ParkingTicket) nếu nó đỗ quá thời gian đỗ đã mua.  
Viết một chương trình demo việc hoạt động của các lớp này khi kết hợp với nhau.
*/