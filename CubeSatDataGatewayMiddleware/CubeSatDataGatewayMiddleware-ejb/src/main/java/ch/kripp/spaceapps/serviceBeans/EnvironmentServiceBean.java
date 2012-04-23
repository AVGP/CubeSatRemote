package ch.kripp.spaceapps.serviceBeans;

import ch.kripp.spaceapps.ServiceModels.EnvironmentModel;
import ch.kripp.spaceapps.domain.Environment.EnvironmentInfo;
import ch.kripp.spaceapps.domain.entities.CfgEnvironmentDAO;

import javax.ejb.EJB;
import javax.ejb.Stateless;

/**
 *
 * @author frank
 */
@Stateless
public class EnvironmentServiceBean {

    @EJB
    private EnvironmentModel environmentModel;

    public EnvironmentServiceBean()
    {
    }

    public EnvironmentServiceBean(EnvironmentModel model)
    {
         this.environmentModel = model;
    }

    public EnvironmentInfo getEnvironmentInfo()
    {

        CfgEnvironmentDAO dao = this.environmentModel.querySingleCfgEnvironment();

        EnvironmentInfo result = new EnvironmentInfo();

        result.setIdentifier(dao.getMiddleware_version());
        result.setMiddlewareVersion(dao.getMiddleware_version());

        return result;
    }
    
}
