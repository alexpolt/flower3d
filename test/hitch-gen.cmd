
@echo copies = %1, words = %2

perl -n -e "for $x (1..%1) { for $i (1..%2) { if(/.+/) { $s=$_; $s=~s/$/$i/; print $s; }}}" hitch3.txt > hitch5.txt

