# SoalShiftSISOP20_modul1_T02
Repository Sebagai Laporan Resmi Soal Shift Modul 1 Praktikum Sistem Operasi 2020\
Disusun oleh : 
- I Gde Made Bhaskara Jala Dhananjaya (05311840000007)
- Azmi (05311840000047)

# Daftar Isi
## [Soal 1](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#soal-1---awk-untuk-menyaring-data)
- [Penyelesaian Soal 1A](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#1a---menampilkan-region-dengan-profit-paling-sedikit)
- [Penyelesaian Soal 1B](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#1b---menampilkan-2-state-dengan-profit-paling-sedikit)
- [Penyelesaian Soal 1C](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#1c---menampilkan-10-product-name-dengan-profit-paling-sedikit)
- [Dokumentasi Output yang Dihasilkan](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#gambar-dibawah-ini-adalah-hasil-dari-script-penyelesaian-soal-nomor-1)

## [Soal 2](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#soal-2---membuat-password-random-dan-mengenkripsi-file-dengan-ceaser)
- [Penyelesaian Soal 2A dan 2B](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#2a-dan-2b---membuat-password-random-dan-memberi-namajudul-pada-file)
- [Penyelesaian Soal 2C](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#2c---mengenkripsi-judul-file)
- [Penyelesaian Soal 2D](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#2d---mendekripsi-judul-file-yang-dienkripsi)
- [Dokumentasi Output yang Dihasilkan](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#gambar-dibawah-ini-adalah-hasil-dari-script-penyelesaian-soal-nomor-2)

## [Soal 3](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#soal-3---mengunduh-gambar-dan-melakukan-pemisahan-gambar-yang-identik)
- [Penyelesaian Soal 3A](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#3a---mengunduh-28-gambar-dari-link-yang-diberikan)
- [Dokumentasi Output yang Dihasilkan 3A](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02/blob/master/README.md#gambar-dibawah-ini-adalah-hasil-dari-script-penyelesaian-soal-nomor-3a)
- [Penyelesaian Soal 3B](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#3b---menjalankan-crontab-untuk-menjalankan-program-secara-otomatis)
- [Penyelesaian Soal 3C](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#3c---mengidentifikasi-gambar-yang-identik-dan-memisahkannya)
- [Dokumentasi Output yang Dihasilkan 3C](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#gambar-dibawah-ini-adalah-hasil-dari-script-penyelesaian-soal-nomor-3c)

## [Kendala yang Dialami](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02#kendala-yang-dialami-1)



# Soal 1 - AWK untuk Menyaring Data
Whits adalah seorang mahasiswa teknik informatika. Dia mendapatkan tugas praktikum untuk membuat laporan berdasarkan data yang ada pada file “Sample-Superstore.tsv”. Namun dia tidak dapat menyelesaikan tugas tersebut. Laporan yang diminta berupa : 

***a.*** Tentukan wilayah Region yang memiliki keuntungan (profit) paling sedikit \
***b.*** Tampilkan 2 negara bagian (state) yang memiliki keuntungan (profit) paling sedikit berdasarkan hasil poin a \
***c.*** Tampilkan 10 produk (product name) yang memiliki keuntungan (profit) paling sedikit berdasarkan hasil poin b 

Whits memohon kepada kalian yang sudah jago mengolah data untuk mengerjakan laporan tersebut.

File untuk penyelesaian soal ini ada disini : [Source Code Soal 1](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02/tree/master/Soal1)

Untuk menyelesaikan persoalan nomor 1, kami menggunakan syntax code sebagai berikut.
```
#!/bin/bash

echo "1 A - Region dengan profit paling kecil"
awk -F \\t 'FNR>1{array[$13]+=$21}END{for(region in array)print array[region], region}' Sample-Superstore.tsv | sort -g | awk -F " " '{print $2}' | head -n 1
echo "---------------------------------------------------------------------"
echo "1 B - 2 Negara bagian dengan profit paling kecil"
awk -F \\t 'FNR>1{if($13=="Central")array[$11]+=$21}END{for(region in array)print array[region], region}' Sample-Superstore.tsv | sort -g | awk -F " " '{print $2}' | head -n 2
echo "---------------------------------------------------------------------"
echo "1 C - 10 Produk dengan profit paling kecil"
awk -F \\t 'FNR>1{if($11=="Texas" || $11=="Illinois")array[$17]+=$21}END{for(region in array)print array[region], region}' Sample-Superstore.tsv | sort -g | head -n 10

```
## 1A - Menampilkan Region dengan Profit Paling Sedikit
```
echo "1 A - Region dengan profit paling kecil"
awk -F \\t 'FNR>1{array[$13]+=$21}END{for(region in array)print array[region], region}' Sample-Superstore.tsv | sort -g | awk -F " " '{print $2}' | head -n 1
```

- Untuk soal nomor 1a, ditandai dengan `echo "1 A - Region dengan profit paling kecil"`. 
- Kemudian menggunakan `awk -F \\t` untuk blablabla. Kemudian `FNR>1` ***(For Number Rows)*** artinya baris yang dibaca adalah baris yang lebih dari baris pertama (2++). 
- Kemudian `{array[$13]+=$21}` berfungsi untuk memasukan nilai yang ada dalam field 13 ***(field region)*** ke dalam array, lalu nilai yang ada field 21 di-***sum*** atau dijumlahkan semuanya. 
- Kemudian `END{for(region in array)print array[region], region` berfungsi untuk menampilkan region yang ada dalam array beserta dengan jumlah profitnya masing-masing. 
- `Sample-Superstore.tsv` adalah file yang merupakan ***source data***. 
- `sort -g` digunakan untuk mengurutkan output dari yang terkecil dan dari atas. 
- `awk -F " " '{print $2}'` berfungsi untuk memberi pemisah antara field berupa " " (spasi) dan yang di-***print*** hanya field kedua. 
- Dan terakhir `head -n 1` berfungsi untuk menampilkan output baris 1 saja (paling atas).

## 1B - Menampilkan 2 State dengan Profit Paling Sedikit
```
echo "1 B - 2 Negara bagian dengan profit paling kecil" 
awk -F \\t 'FNR>1{if($13=="Central")array[$11]+=$21}END{for(region in array)print array[region], region}' Sample-Superstore.tsv | sort -g | awk -F " " '{print $2}' | head -n 2
```

- Soal nomor 1b ditandai dengan `echo "1 B - 2 Negara bagian dengan profit paling kecil"`. 
- Sama seperti soal ***1a***, `awk -F \\t` digunakan untuk blablabla. 
- Kemudian, `FNR>1{if($13=="Central")array[$11]+=$21}END{for(region in array)print array[region], region}` artinya untuk untuk baris yang lebih dari baris pertama, jika field 13 ***(Region)*** merupakan ***Central***, field 11 dari Region Central dimasukkan ke dalam array dan field 21 ***(profit)*** dijumlahkan. 
- Output yang dihasilkan adalah data di field 11 ***(State)*** beserta profitnya masing-masing. 
- `sort -g` untuk mengurutkan data dari yang terkecil. 
- `awk -F " " '{print $2}'` berfungsi untuk memberi pemisah spasi diantara field output dan yang di-***print*** field ke 2 saja. 
- `head -n 2` berfungsi untuk menampilkan 2 output teratas. sesuai dengan permintaan soal.

## 1C - Menampilkan 10 Product Name dengan Profit Paling Sedikit
```
echo "1 C - 10 Produk dengan profit paling kecil"
awk -F \\t 'FNR>1{if($11=="Texas" || $11=="Illinois")array[$17]+=$21}END{for(region in array)print array[region], region}' Sample-Superstore.tsv | sort -g | head -n 10
```

- Soal nomor 1c ditandai dengan `echo "1 C - 10 Produk dengan profit paling kecil"`. 
- Sama seperti persoalan sebelumnya, `awk -F \\t` digunakan untuk blablabla. 
- Kemudian, `FNR>1{if($11=="Texas" || $11=="Illinois")array[$17]+=$21}END{for(region in array)print array[region], region}` artinya untuk untuk baris yang lebih dari baris pertama, jika field 11 ***(Region)*** merupakan ***Texas*** atau ***Illinois***, field 17 ***(product name)*** dari State yang dimaksud dimasukkan ke dalam array dan field 21 ***(profit)*** dijumlahkan. 
- Output yang dihasilkan adalah data di field 17 ***(product name)*** beserta profitnya masing-masing. 
- `sort -g` untuk mengurutkan data dari yang terkecil. 
- Dan `head -n 10` untuk menampilkan 10 data teratas.

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 1.

![](Screenshot/Soal1/1.png)

# Soal 2 - Membuat Password Random dan Mengenkripsi File dengan Ceaser
Suatu siang, laptop Randolf dan Afairuzr dibajak oleh seseorang dan laptop mereka berisi data-data penting. Agar kejadian tersebut tidak terulang kembali, mereka meminta bantuan Whits dan tercetus ide sebagai berikut :

***a.*** Membuat script bash yang mebuat password acak sebanyak 28 karakter yang terdapat huruf kecil, huruf besar, dan angka \
***b.*** Password tersebut disimpan dalam file berektensi .txt dengan nama yang diinputkan hanya terdiri dari karakter alphabet \
***c.*** Kemudian judul file dienkripsi menggunakan Ceaser Cipher yang disesuaikan dengan jam dibuatnya file \
***d.*** Menyertakan script bash untuk mendekripsinya 

Untuk itu, Whits meminta bantuan kalian untuk menyelesaikan persoalan-persoalan diatas.

File untuk penyelesaian soal ini ada disini : [Source Code Soal 2](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02/tree/master/Soal2)

## 2A dan 2B - Membuat Password Random dan Memberi Nama/Judul pada File
Untuk menyelesaikan persoalan nomor 2A, syntax yang digunakan adalah sebagai berikut. 
```
#!/bin/bash

ngasal=`< /dev/urandom  tr -dc A-Za-z0-9 | fold -w 28 | head -n 1`

echo "Tulis Judul Filenya :"
read name
judul=`echo "$name" | tr -dc A-Za-z`
echo "$ngasal" >> $judul.txt
```
- ***ngasal=***`< /dev/urandom  tr -dc A-Za-z0-9 | fold -w 28 | head -n 1` Pertama kita membuat variabel ***ngasal*** dimana didalam variabel terdapat password random yang telah dibuat. 
- `< /dev/urandom  tr -dc A-Za-z0-9` berfungsi untuk membuat password secara random. `tr -dc A-Za-z0-9` berfungsi menghapus semua karakter di luar karakter yang dideklarasi.
- `fold -w 28` berfungsi untuk mambatasi panjang karakter yang dibuat, dimana `-w` membatasi lebarnya yakni 28 karakter.
- `head -n 1` untuk menampilkan satu baris teratas saja.
- `echo "Tulis Judul Filenya :"` sebagai perintah untuk memasukan judul file.
- `read name` berfungsi untuk membaca judul yang telah dibuat.
- ***judul***=`echo "$name" | tr -dc A-Za-z` membuat variabel judul. Kemudian ***print*** judul yang telah dimasukkan sebelumnya dan `tr -dc A-Za-z` untuk menghapus karakter di luar variabel yang ditentukan (hanya boleh alphabet).
- `echo "$ngasal" >> $judul.txt` berfungsi untuk memasukan password random yang telah dibuat ke dalam file.

## 2C - Mengenkripsi Judul File
Untuk menyelesaikan persoalan nomor 2C, syntax yang digunakan adalah sebagai berikut. 
```
#!/bin/bash

for namafile in $@
  do
   waktu=`date +%H -r $namafile`
   namafilelama=`basename $namafile .txt`

   namafilebaru=`echo $namafilelama | caesar $waktu`
   mv $namafile $namafilebaru.txt
 done
 ```
 - `for namafile in $@` untuk membaca semua variabel ***namafile*** dan `$@` memasukan semua input yang ada.
 - ***waktu***=`date +%H -r $namafile` membuat variabel waktu, lalu membaca waktu (jam) dibuatnya file tersebut dan menyimpannya di variabel waktu.
 - ***namafilelama***=`basename $namafile .txt` membuat variabel namafilelama, kemudian `basename $namafile .txt` untuk memisahkan nama file dengan ekstensi file .txt.
 - ***namafilebaru***=`echo $namafilelama | caesar $waktu` membuat variabel namafilebaru. Kemudian data yang disimpan di variabel ***namafilelama*** dienkripsi menggunakan teknik ceaser dengan pergeseran berdasarkan data yang ada dalam variabel ***waktu***.
 - `mv $namafile $namafilebaru.txt` untuk mengganti data yang ada dalam variabel ***namafile*** dengan data yang ada dalam variabel ***namafilebaru*** (hasil enkripsi) dengan ekstensi file .txt seperti sebelumnya.
  
  ## 2D - Mendekripsi Judul File yang Dienkripsi
  Untuk menyelesaikan persoalan nomor 2D, syntax yang digunakan adalah sebagai berikut. 
  ```
  #!/bin/bash

for judul in $@
  do
   waktu=`date +%H -r $judul`
   judullama=`basename $judul .txt`
   waktubaru=`expr 26 - $waktu`
   judulbaru=`echo $judullama | caesar $waktubaru`
   mv $judul $judulbaru.txt
done
```
- `for judul in $@` untuk membaca semua variabel ***judul*** dan `$@` memasukan semua input yang ada.
- ***waktu***=`date +%H -r $judul` membuat variabel waktu, lalu membaca waktu (jam) dibuatnya file tersebut dan menyimpannya di variabel waktu.
- ***judullama***=`basename $judul .txt` membuat variabel judullama, kemudian `basename $judul .txt` untuk memisahkan nama file dengan ekstensi file .txt.
- ***waktubaru***=`expr 26 - $waktu` membuat variabel waktubaru. Kemudian `expr 26 - $waktu` berfungsi untuk blablabla
- ***judulbaru***=`echo $judullama | caesar $waktubaru` membuat variabel ***judulbaru***. Kemudian data yang disimpan di variabel ***judullama*** didekripsi menggunakan teknik ceaser dengan pergeseran berdasarkan data yang ada dalam variabel ***waktubaru***.
- `mv $judul $judulbaru.txt` untuk mengganti data yang ada dalam variabel ***judul*** dengan data yang ada dalam variabel ***judulbaru*** (hasil dekripsi) dengan ekstensi file .txt seperti sebelumnya.

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 2.

![](Screenshot/Soal2/1.png)

# Soal 3 - Mengunduh Gambar dan Melakukan Pemisahan gambar yang Identik
Kusuma telah sering dicampakkan oleh pujaan hatinya sehingga kalian berniat untuk menghiburnya dengan mengirimkan foto kucing kepadanya. Kemudian kalian memiliki ide sebagai berikut :

***a.*** Mengunduh 28 gambar dari "https://loremflickr.com/320/240/cat" dengan command ***wget*** dengan format nama file "pdkt_kusuma_NO" dan menyimpan ***log messages wget*** kedalam file ***wget.log***. \
***b.*** Menggunakan crontab untuk melakukan menjalankan script setiap 8 jam sekali dimulai pukul 06.00 setiap hari kecuali Hari Sabtu \
***c.*** Karena gambar yang diunduh bersifat random, jika ada gambar yang sama/identik, sisakan 1 gambar untuk Kusuma dan masukan gambar tersebut folder "kenangan" dengan format penamaan "kenangan_NO", sedangkan gambar identik lainnya dimasukan ke folder "duplikasi" dengan format penamaan file "duplikasi_NO" 

Hint : gunakan ***wget.log*** untuk membuat ***location.log*** yang isinya adalah hasil dari grep "Location:". 

Untuk itu kalian diminta untuk membantu menenangkan hati Kusuma :)

File untuk penyelesaian soal ini ada disini : [Source Code Soal 3](https://github.com/Bhaskaraa/SoalShiftSISOP20_modul1_T02/tree/master/Soal3)

## 3A - Mengunduh 28 Gambar dari Link yang Diberikan
Untuk menyelesaikan persoalan nomor 3a, syntax yang digunakan adalah sebagai berikut.
```
#!/bin/bash/

banyakfile=`ls | grep "pdkt_kusuma" | cut -d '_' -f 3 | sort -n | tail -1`
if [[ $banyakfile =~ [^0-9] ]] 
  then
  banyakfile=0
fi

awal=`expr $banyakfile + 1`
akhir=`expr $banyakfile + 28`

for ((i=awal;i<=akhir;i++))
do
  wget -O "pdkt_kusuma_$i" -a wget.log "https://loremflickr.com/320/240/cat"
done

grep "Location" wget.log >> location.log

```
- ***banyakfile***=`ls | grep "pdkt_kusuma" | cut -d '_' -f 3 | sort -n | tail -1` Kita buat variabel bernama ***banyakfile*** kemudian `grep "pdkt_kusuma`berfungsi untuk mengambil file dengan pattern yang telah ditentukan. `cut -d '_' -f 3` berfungsi untuk menghapus karakter garis bawah sehingga variabel tersebut hanya dipisahkan dengan spasi dan terbagi menjadi tiga field, dan akhirnya yang dimasukan ke field ketiga adalah field ke 3. `sort -n` untuk mengurutkan berdasarkan urutan numerik. `tail -1` mengambil 1 output yang paling bawah.
- `[[ $banyakfile =~ [^0-9] ]]` berfungsi untuk mengecek apakah ***banyakfile*** terdiri dari angka 0-9.
- `banyakfile=0` Jika tidak ada angka 0-9 maka ***banyakfile*** dimulai dari 0.
- ***awal***=`expr $banyakfile + 1` Buat variabel baru bernama ***awal***. `expr $banyakfile + 1` ***expr*** adalah syntax agar dapat melakukan operasi aritmatika dimana variabel awal merupakan ***banyakvariabel*** ditambah dengan 1.
- ***akhir=***`expr $banyakfile + 28` Buat variabel baru bernama ***akhir***. `expr $banyakfile + 28` ***expr*** adalah syntax agar dapat melakukan operasi aritmatika dimana variabel akhhir merupakan ***banyakvariabel*** ditambah dengan 28.
- `for ((i=awal;i<=akhir;i++))` Untuk looping  ketika i=awal kemudian i kurang dari sama dengan akhir maka i di increment.
- `wget -O "pdkt_kusuma_$i" -a wget.log "https://loremflickr.com/320/240/cat"` berfungsi untuk mengunduh gambar dari tautan yang diberikan. `wget -O "pdkt_kusuma_$i"` berfungsi untuk memberi pola nama pada file yang diunduh.
- `grep "Location" wget.log >> location.log` mengambil data "Location" yang ada dalam wget.log kemudian dipindahkan ke location.log.

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 3A.

![](Screenshot/Soal3/1.png)

## 3B - Menjalankan Crontab untuk Menjalankan Program Secara Otomatis
Untuk menyelesaikan persoalan nomor 3b, syntax yang digunakan adalah sebagai berikut.
```
5 6,14,22 * * 0-5 /bin/bash /home/bhaskarajd/Soal3/Soal3.sh

```
- ***5*** Karena yang pada soal jam yang ditunjukkan di awal adalah jam 06.05 maka di bintang pertama adalah menit ke-5.
- ***6,14,22*** Karena yang diminta soal adalah jam 6 dan setiap 8 jam, maka kelipatan 8 setelah jam 6 adalah jam 6,14,22.
- ***0-5*** Karena yang diminta soal adalah setiap hari kecuali hari sabtu, maka 0-5 karena di crontab 0 adalah hari Minggu dan Sabtu adalah 6.
- `/bin/bash /home/bhaskarajd/Soal3/Soal3.sh` berfungsi sebagai perintah untuk menjalan script bash.

## 3C - Mengidentifikasi Gambar yang Identik dan Memisahkannya
Untuk menyelesaikan persoalan nomer 3c, syntax yang digunakan adalah sebagai berikut.
```
#!/bin/bash

akhir=`ls | grep "pdkt_kusuma" | cut -d "_" -f 3 | sort -n | tail -1`

if [[ `ls | grep "kenangan"` != "kenangan" ]]
then
  mkdir ./kenangan
fi

if [[ `ls | grep "duplikasi"` != "duplikasi" ]]
then
  mkdir ./duplikasi
fi

arr=""

for ((i=1;i<=akhir;i++))
do
  loc="`cat wget.log | grep "Location:" | head -$i | tail -1 | cut -d " " -f 2`"
  Duplikasi=`echo -e $arr | awk -v loc=$loc 'BEGIN {Duplikasi=0} {if (loc==$0) Duplikasi=1} END {printf "%d", Duplikasi}'`
  
if [[ $Duplikasi == 1 ]]
  then
    mv pdkt_kusuma_$i ./duplikasi/duplikasi_$i
  else
    arr="$arr$loc\n"
    mv pdkt_kusuma_$i ./kenangan/kenangan_$i
  fi
done

```
- ***akhir***=`ls | grep "pdkt_kusuma" | cut -d "_" -f 3 | sort -n | tail -1` Kita buat variabel bernama ***akhir*** kemudian `grep "pdkt_kusuma` berfungsi untuk mengambil file dengan pola yang ditentukan. `cut -d '_' -f 3` berfungsi untuk menghapus karakter garis bawah yang memisahkan pola dan mengambil field ke 3. `sort -n` untuk mengurutkan berdasarkan urutan numerik. `tail -1` mengambil 1 output terakhir dari bawah.
- `[[ `ls | grep "kenangan"` != "kenangan" ]]` berfungsi untuk mengambil file dengan pola yang ditentukan dan jika tidak ada file/folder yang memiliki pola yang sama maka  `mkdir ./kenangan` berfungsi untuk membuat folder kenangan.
- `[[ `ls | grep "duplikasi"` != "duplikasi" ]]` berfungsi untuk mengambil file dengan pola yang ditentukan dan jika tidak ada file/folder yang memiliki pola yang sama maka  `mkdir ./duplikasi` berfungsi untuk membuat folder duplikasi.
- `arr=""` Buat variabel array yang isinya masih kosong.
- `for ((i=1;i<=akhir;i++))` berfungsi untuk looping ketika i=1 kemudian i kurang dari sama dengan akhir maka i di increment.
- ***loc***="`cat wget.log | grep "Location:" | head -$i | tail -1 | cut -d " " -f 2`" pertama kita membuat variabel ***loc***. Kemudian `grep "Location:"` berfungsi untuk mengambil data ***Location:***. `head -$i` berfungsi untuk menampilkan file pada urutan atas sejumlah nilai ***i***. `cut -d " " -f 2` berfungsi untuk menghapus karakter spasi dan hanya mengambil data yang ada di field ke 2.
- ***Duplikasi***=`echo -e $arr | awk -v loc=$loc 'BEGIN {Duplikasi=0} {if (loc==$0) Duplikasi=1} END {printf "%d", Duplikasi}'` pertama kita membuat variabel bernama Duplikasi. `echo -e $arr` kemudian ***print*** nilai dari variabel ***arr***. `awk -v loc=$loc` kemudian jalankan awk dengan fungsi nilai dari variabel ***loc***. `BEGIN {Duplikasi=0} {if (loc==$0) Duplikasi=1}` berfungsi untuk mencari gambar yang identik dengan membandingkan lokasinya, jika ada yang identik maka variabel Duplikasi akan bernilai 1. `END {printf "%d", Duplikasi` dan diakhir akan di-***print*** nilai lokasi dari variabel Duplikasi tersebut. 
- `[[ $Duplikasi == 1 ]]` jika nilai Duplikasi sama dengan 1 atau dengan kata lain ada gambar yang identik `mv pdkt_kusuma_$i ./duplikasi/duplikasi_$i` berfungsi untuk memindahkan file dengan pola ***"pdkt_kusuma_$i*** ke folder duplikasi dan mengubah namanya menjadi berpola ***duplikasi_$1***.
- `arr="$arr$loc\n"` menjelaskan bahwa dalam variabel ***arr*** berisi data dari arr dan loc. `mv pdkt_kusuma_$i ./kenangan/kenangan_$i` berfungsi untuk memindahkan file dengan pola ***"pdkt_kusuma_$i*** ke folder kenangan dan mengubah namanya menjadi ***kenangan_$1***.

## Gambar dibawah ini adalah hasil dari script penyelesaian soal nomor 3C.

![](Screenshot/Soal3/2.png)
![](Screenshot/Soal3/3.png)
![](Screenshot/Soal3/4.png)

## Kendala yang Dialami
***1.*** Penulis masih menyesuaikan diri dengan sistem operasi LINUX/Ubuntu sehingga ada beberapa kendala dalam menggunakan terminal. \
***2.*** Soal jauh diatas kemampuan penulis terutama nomor 1. \
***3.*** Banyak command baru yang penulis belum pernah dengar maupun gunakan sebelumnya. \
***4.*** Penulis belum memahami dengan penuh yang diberikan pada modul 3. \
***5.*** Karena keadaan yang WFH, penulis sulit berdiskusi dengan anggota kelompok. \
