
/*
Một số lưu ý về hàm seekg(): (dùng trong ios::in)
    namefile.seekg(x, y);
        - trong đó:
            + X số byte cần dịch chuyển luôn luôn là 1 con số nguyên:
                * n số âm : nghĩa là dịch về bên tay trái n số;
                * n số dương : nghĩa là dịch về bên tay phải n số.
            + Y Vị trí bắt đầu dịch:
                * 0 or ios::beg or SEEK_SET: dịch từ vị trí đầu tệp;
                * 1 or ios::cur or SEEK_CUR : dịch từ vị trí hiện tại của tệp;
                * 2 or ios::end or SEEK_END: dịch từ vị trí cuối của tệp;
                
Một số lưu ý về hàm seekp(): (dùng trong ios::out)
    namefile.seekg(x, y);
        - trong đó:
            + X số byte cần dịch chuyển luôn luôn là 1 con số nguyên:
                * n số âm : nghĩa là dịch về bên tay trái n số;
                * n số dương : nghĩa là dịch về bên tay phải n số.
            + Y Vị trí bắt đầu dịch:
                * 0 or ios::beg or SEEK_SET: dịch từ vị trí đầu tệp;
                * 1 or ios::cur or SEEK_CUR : dịch từ vị trí hiện tại của tệp;
                * 2 or ios::end or SEEK_END: dịch từ vị trí cuối của tệp;
*/