                        if (pattern.Contains("mjsyst_r")) {
                            for (int r : r_vals) {
                                histName2016 = Form("bin%i/%s", ibin, Form(pattern.Data(), procname.Data(), r, ind_ijet, procname.Data(), Form("2016%s", var.Data())));
                                histName1718 = Form("bin%i/%s", ibin, Form(pattern.Data(), procname.Data(), r, ind_ijet, procname.Data(), Form("1718%s", var.Data())));
                                mergedHistName = Form(pattern.Data(), procname.Data(), r, ind_ijet, procname.Data(), Form("201678%s", var.Data()));

                                TH1F *hist2016 = (TH1F*)inputFile->Get(histName2016);
                                TH1F *hist1718 = (TH1F*)inputFile->Get(histName1718);
                                if (hist2016 || hist1718) {
                                    TH1F *mergedHist = nullptr;
                                    if (hist2016) mergedHist = (TH1F*)hist2016->Clone(mergedHistName);
                                    else mergedHist = (TH1F*)hist1718->Clone(mergedHistName);

                                    if (hist2016 && hist1718) mergedHist->Add(hist1718);

                                    mergedHist->Write();
                                }
                            }
                        } else {
                            histName2016 = Form("bin%i/%s", ibin, Form(pattern.Data(), procname.Data(), ikap, ind_ijet, procname.Data(), Form("2016%s", var.Data())));
                            histName1718 = Form("bin%i/%s", ibin, Form(pattern.Data(), procname.Data(), ikap, ind_ijet, procname.Data(), Form("1718%s", var.Data())));
                            mergedHistName = Form(pattern.Data(), procname.Data(), ikap, ind_ijet, procname.Data(), Form("201678%s", var.Data()));

                            TH1F *hist2016 = (TH1F*)inputFile->Get(histName2016);
                            TH1F *hist1718 = (TH1F*)inputFile->Get(histName1718);
                            if (hist2016 || hist1718) {
                                TH1F *mergedHist = nullptr;
                                if (hist2016) mergedHist = (TH1F*)hist2016->Clone(mergedHistName);
                                else mergedHist = (TH1F*)hist1718->Clone(mergedHistName);

                                if (hist2016 && hist1718) mergedHist->Add(hist1718);

                                mergedHist->Write();
                            }
                        }
                    }
                }
            }
        }
    }

    inputFile->Close();
    outputFile->Close();

    std::cout << "Merged histograms saved to merged_output.root" << std::endl;
}
