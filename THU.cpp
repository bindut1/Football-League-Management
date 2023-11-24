fstream file("HistoryMatch.txt", ios::in);
    fstream tempFile("tempHistoryMatch.txt", ios::out | ios::app);
    tempFile << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String idr, id1, goal1, id2, goal2, time, date, address;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    idr = idr + tmp[i];
                else if (check == 2 && status)
                    id1 = id1 + tmp[i];
                else if (check == 3 && status)
                    goal1 = goal1 + tmp[i];
                else if (check == 4 && status)
                    id2 = id2 + tmp[i];
                else if (check == 5 && status)
                    goal2 = goal2 + tmp[i];
                else if (check == 6 && status)
                    time = time + tmp[i];
                else if (check == 7 && status)
                    date = date + tmp[i];
                else if (check == 8 && status && tmp[i] != '\n')
                {
                    address = address + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }


            
        }
    }