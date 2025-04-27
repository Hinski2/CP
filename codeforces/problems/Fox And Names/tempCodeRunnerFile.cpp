      leaf.pb(u);
            }
        }
    }

    if(ans.size() != 'z' - 'a' + 1){
        cout << "Impossible" << endl;
    } else {
        for(auto u: ans)
            cout << u;
        cout << endl;
    }
}
