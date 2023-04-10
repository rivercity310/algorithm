package com.example.tmp.repository;

import com.example.tmp.domain.Account;
import com.example.tmp.domain.QAccount;
import org.springframework.data.jpa.repository.support.QuerydslRepositorySupport;

import java.util.List;

public class AccountCustomRepositoryImpl extends QuerydslRepositorySupport implements AccountCustomRepository {
    public AccountCustomRepositoryImpl() {
        super(Account.class);
    }

    @Override
    public List<Account> findRecentlyRegistered(int limit) {
        final QAccount account = QAccount.account;
        return from(account)
                .limit(limit)
                .orderBy(account.createdAt.desc())
                .fetch();
    }
}
